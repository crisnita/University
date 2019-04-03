"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/22/2018 19:51
"""


class ExceptionRepoEnroll(Exception):
    pass


class RepositoryEnroll:
    def __init__(self):
        self.__lst = []

    def addPair(self, pair):
        for i in range(len(self.__lst)):
            if str(pair.get_p()) == str(self.__lst[i].get_p()) and str(pair.get_e()) == str(self.__lst[i].get_e()):
                raise ExceptionRepoEnroll()
        self.__lst.append(pair)

    def getAllPairs(self):
        return list(self.__lst)

    def getAllPairsWithID(self, id):
        lst2 = []
        for i in range(len(self.__lst)):
            if self.__lst[i].get_p() == id:
                lst2.append(self.__lst[i].get_e())
        return lst2
