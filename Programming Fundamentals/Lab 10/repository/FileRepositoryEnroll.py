"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/22/2018 19:51
"""
from domain.entities import PairID


class ExceptionRepoEnroll(Exception):
    pass


class FileRepositoryEnroll:
    def __init__(self):
        self.__lst = self.__loadFromFile()

    def clearRepositoryEnroll(self):
        f = open("repository/enroll.txt", "w")
        f.close()

    def __loadFromFile(self):
        try:
            f = open("repository/enroll.txt", "r")
        except IOError:
            print("Couldn't open file!")
            return []
        line = f.readline().strip()
        content = []
        while line != "":
            attrs = line.split("|")
            st = PairID(attrs[0], attrs[1])
            content.append(st)
            line = f.readline().strip()
        f.close()
        return content

    def __saveInFile(self, pairs):
        with open("repository/enroll.txt", "w") as f:
            for pair in pairs:
                s = str(pair.get_p()) + "|" + str(pair.get_e()) + "\n"
                f.write(s)

    def addPair(self, pair):
        for i in range(len(self.__lst)):
            if str(pair.get_p()) == str(self.__lst[i].get_p()) and str(pair.get_e()) == str(self.__lst[i].get_e()):
                raise ExceptionRepoEnroll()
        self.__lst.append(pair)
        self.__saveInFile(self.__lst)

    def getAllPairs(self):
        return list(self.__lst)

    def getAllPairsWithID(self, id):
        lst2 = []
        for i in range(len(self.__lst)):
            if self.__lst[i].get_p() == id:
                lst2.append(self.__lst[i].get_e())
        return lst2

    def clear_file(self):
        self.__saveInFile([])
        self.__lst = []

    def load(self):
        self.__lst = self.__loadFromFile()

    def save(self):
        self.__saveInFile(self.__lst)

