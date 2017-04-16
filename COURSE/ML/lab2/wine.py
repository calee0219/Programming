#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import time
from sklearn.neighbors import KNeighborsClassifier as KNN
from sklearn.model_selection import KFold
from sklearn.metrics import confusion_matrix
from sklearn.preprocessing import normalize
from scipy.spatial.distance import cosine
import pandas as pd
import numpy as np

dataset_url = 'http://mlr.cs.umass.edu/ml/machine-learning-databases/' + \
                'wine-quality/winequality-white.csv'
data = pd.read_csv(dataset_url, sep=';')
# ls = list(data)
# ls.remove('quality')
# feature = pd.DataFrame(data, columns=ls)
# target = pd.DataFrame(data, columns=['quality'])
feature = normalize(data.iloc[:, 0:-2])
target = np.ravel(data.iloc[:, -1])

def cosDist(x, y):
    return np.arccos(cosine(x, y))/np.pi


def resubstation(dist, algo):
    print("resubstation, algo=%s, dist=%s" % (algo, dist))
    start_time = time.time()
    if dist == 'cosDist':
        nbr = KNN(n_neighbors=11, algorithm=algo, \
                metric=cosDist)
    else:
        nbr = KNN(n_neighbors=11, algorithm=algo, \
                metric=dist, weights='distance')
    nbr.fit(feature, target)
    pred = nbr.predict(feature)
    m = confusion_matrix(target, pred, labels=[1,2,3,4,5,6,7,8,9,10])
    print(np.trace(m)/np.sum(m))
    print("--- %s seconds ---" % (time.time() - start_time))


def kfold(dist, algo, foldNum):
    print("kFold, foldNum=%d, algo=%s, dist=%s" % (foldNum, algo, dist))
    start_time = time.time()
    kf = KFold(n_splits=12, shuffle=True)
    total_rate = 0
    for train, test in kf.split(feature):
        train_feature, test_feature = feature[train], feature[test]
        train_target, test_target = target[train], target[test]
        if dist == 'cosDist':
            nbr = KNN(n_neighbors=11, algorithm=algo, \
                    metric=cosDist)
        else:
            nbr = KNN(n_neighbors=11, algorithm=algo, \
                    metric=dist, weights='distance')
        nbr.fit(train_feature, train_target)
        pred = nbr.predict(test_feature)
        m = confusion_matrix(test_target, pred, labels=[1,2,3,4,5,6,7,8,9,10])
        rate = np.trace(m)/np.sum(m)
        total_rate += rate
    print(total_rate/12)
    print("--- %s seconds ---" % (time.time() - start_time))


resubstation(dist='manhattan', algo='brute')
resubstation(dist='manhattan', algo='kd_tree')
resubstation(dist='manhattan', algo='ball_tree')
print()
resubstation(dist='euclidean', algo='brute')
resubstation(dist='euclidean', algo='kd_tree')
resubstation(dist='euclidean', algo='ball_tree')
print()
kfold(dist='manhattan', algo='brute', foldNum=12)
kfold(dist='manhattan', algo='kd_tree', foldNum=12)
kfold(dist='manhattan', algo='ball_tree', foldNum=12)
print()
kfold(dist='euclidean', algo='brute', foldNum=12)
kfold(dist='euclidean', algo='kd_tree', foldNum=12)
kfold(dist='euclidean', algo='ball_tree', foldNum=12)
print()
resubstation(dist='mahalanobis', algo='brute')
kfold(dist='mahalanobis', algo='brute', foldNum=12)
print()
resubstation(dist='cosDist', algo='brute')
kfold(dist='cosDist', algo='brute', foldNum=12)