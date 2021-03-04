import numpy as np
import matplotlib.pyplot as plt
import h5py
from lr_utils import load_dataset
train_set_x_orig , train_set_y , test_set_x_orig , test_set_y , classes = load_dataset()

#压缩图片至二维
train_set_x_flatten = train_set_x_orig.reshape(train_set_x_orig.shape[0],-1).T 
test_set_x_flatten = test_set_x_orig.reshape(test_set_x_orig.shape[0],-1).T

# 数据居中和标转化
train_set_x = train_set_x_flatten / 255 
test_set_x = test_set_x_flatten / 255

# sigmoid函数
def sigmoid(z):
    s = 1 / (1 + np.exp(-z))
    return s

# 初始化参数w和b
def initialize_with_zeros(dim):
    w = np.zeros(shape = (dim, 1))
    b = 0
    assert(w.shape == (dim, 1))
    assert(isinstance(b, float) or isinstance(b,int))
    return (w, b)

# 实现前向和后向传播的成本函数及其梯度
def propagate(w, b, X, Y):
    m = X.shape[1]

    # 正向传播
    A = sigmoid(np.dot(w.T, X) + b)
    cost = -1 / m * np.sum(Y * np.log(A) + (1 - Y) * np.log(1 -  A))

    # 反向传播
    dz = A - Y
    dw = 1/m * np.dot(X,dz.T)
    db = 1/m * np.sum(dz)

    assert(dw.shape == w.shape)
    assert(db.dtype == float)
    cost = np.squeeze(cost)
    assert(cost.shape == ())

    grads = {
                "dw": dw,
                "db": db
    }
    return (grads, cost)

# 不断迭代，计算梯度并改变参数
def optimize(w, b, X, Y, num_iterations, learning_rate, print_cost = False):

    costs = []

    for i in range(num_iterations):

        grads, cost = propagate(w, b, X, Y)

        dw = grads["dw"]
        db = grads["db"]
        
        w = w - learning_rate * dw
        b = b - learning_rate *db

        if i % 100 == 0:
            costs.append(cost)
        
        if(print_cost) and (i % 100 == 0):
            print("迭代的次数： %i , 误差值： %f" % (i,cost))

    params = {
                "w" : w,
                "b" : b
    }
    grads = {
                "dw" : dw,
                "db" : db
    }
    return (params, grads, costs)

# 根据参数w和b来预测X对应的Y
def predict(w, b, X):

    m = X.shape[1]
    Y_prediction = np.zeros((1,m))
    w = w.reshape(X.shape[0], 1)

    z = np.dot(w.T, X) + b
    A = sigmoid(z)
    for i in range (A.shape[1]):
        Y_prediction[0, i] = 1 if A[0,i] > 0.5 else 0
    
    assert (Y_prediction.shape == (1,m))

    return Y_prediction

# 构建逻辑回归模型
def model(X_train, Y_train, X_test, Y_test, num_iterations = 2000, learning_rate = 0.5, print_cost = False):

    w, b = initialize_with_zeros(X_train.shape[0])

    parameters, grads, costs = optimize(w, b, X_train, Y_train, num_iterations, learning_rate, print_cost)

    w, b = parameters["w"], parameters["b"]

    Y_prediction_test = predict(w, b, X_test)
    Y_prediction_train = predict(w, b, X_train)

    print("训练集准确性："  , format(100 - np.mean(np.abs(Y_prediction_train - Y_train)) * 100) ,"%")
    print("测试集准确性："  , format(100 - np.mean(np.abs(Y_prediction_test - Y_test)) * 100) ,"%")

    d = {
            "costs" : costs,
            "Y_prediction_test" : Y_prediction_test,
            "Y_prediction_train" : Y_prediction_train,
            "w" : w,
            "b" : b,
            "learning_rate" : learning_rate,
            "num_iterations":  num_iterations, 
    }
    return d

learning_rates = [0.01, 0.001, 0.0001]
models = {}
for i in learning_rates:
    print("learning rate is: " + str(i))
    models[str(i)] = model(train_set_x, train_set_y, test_set_x, test_set_y, num_iterations = 1500, learning_rate = i, print_cost = False)
    print ('\n' + "-------------------------------------------------------" + '\n')

for i in learning_rates:
    plt.plot(np.squeeze(models[str(i)]["costs"]), label= str(models[str(i)]["learning_rate"]))

plt.ylabel('cost')
plt.xlabel('iterations')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')

plt.show()