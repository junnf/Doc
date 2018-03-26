#!/usr/bin/env python
from numpy import dot
from numpy.linalg import inv
from numpy import array

class LinarRegression():
    def __init__(self, sets_x, sets_y, thetas):
        exercise(self, array(sets_x), array(sets_y), array(thetas))

    def exercise(self,x,y,thetas):
        self.__theta = dot(dot(inv(dot(x.T,x)),x.T),y)
        self.__bias = 0

    def predict(self, elem):
        dot(elem, self.__theta) + self.__bias

def main():
    regression = LinarRegression(sets_x, sets_y, thetas)
    regression.predict()
