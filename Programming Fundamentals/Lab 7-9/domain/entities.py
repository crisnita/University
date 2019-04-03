"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/9/2018 18:34
"""


class Person:

    def __init__(self, id, name, adress):
        self.__id = id
        self.__name = name
        self.__adress = adress


    def get_id(self):
        return self.__id

    def get_name(self):
        return self.__name

    def get_adress(self):
        return self.__adress


    def set_id(self, id):
        self.__id = id

    def set_name(self, name):
        self.__name = name

    def set_adress(self, adress):
        self.__adress = adress

    #def __str__(self):
        #return str(self.__id) + " " + self.__name + " " + self.__adress


class Event:
    def __init__(self, id, date, time, descr):
        self.__id = id
        self.__date = date
        self.__time = time
        self.__descr = descr

    def get_id(self):
        return self.__id

    def get_date(self):
        return self.__date

    def get_time(self):
        return self.__time

    def get_descr(self):
        return self.__descr

    def set_id(self, id):
        self.__id = id

    def set_date(self, date):
        self.__date = date

    def set_time(self, time):
        self.__time = time

    def set_descr(self, descr):
        self.__descr = descr


class PairID:
    def __init__(self, p, e):
        self.__p = p
        self.__e = e

    def get_p(self):
        return self.__p

    def get_e(self):
        return self.__e
