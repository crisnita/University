"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/17/2018 18:14
"""
class ExceptionRepoP(Exception):
    pass

class RepositoryPerson:
    def __init__(self):
        self.__lst = {}


    def getAllPeople(self):
        return list(self.__lst.values())

    def storeElem(self, elem):
        if elem.get_id() in self.__lst:
            raise ExceptionRepoP()
        self.__lst[elem.get_id()] = elem


    def update(self, pers):
        self.__lst[pers.get_id()] = pers

    def deletePers(self, pers):
        del self.__lst[pers.get_id()]

    def findPerson(self, id):
        if id in self.__lst:
            return self.__lst[id]
        return None
