'''
class Caine:

    def __init__(self,id,nume,val):
        self.__id = id
        self.__nume = nume
        self.__val = val
    def getNume(self):
        return self.__nume
    def __eq__(self,other):
        return self.__id == other.__id
'''

t = Test()


