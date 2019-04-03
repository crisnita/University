"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/17/2018 16:50
"""
from domain.entities import Person


class ServicePerson:
    def __init__(self, repo, val):
        self.__repo = repo
        self.__val = val

    def loadPpl(self):
        self.__repo.load()

    def savePpl(self):
        self.__repo.save()

    def getAllPeople(self):
        return self.__repo.getAllPeople()

    def createPerson(self, id, name, adress):
        """
        1) Create person
        2) Validate person ----
        3) Store person in repository
        :param id:
        :param name:
        :param adress:
        :return: a person
        """
        p = Person(id, name, adress)
        self.__val.validatePerson(p)
        self.__repo.storeElem(p)
        return p

    def modPerson(self, id, name, adress):
        pers = Person(id, name, adress)
        self.__repo.update(pers)

    def deletePersonFaraRecursivitate(self, id):
        allPeople = self.__repo.getAllPeople()
        for pers in allPeople:
            if pers.get_id() == id:
                self.__repo.deletePers(pers)

    def deletePerson(self, id):
        allPeople = self.__repo.getAllPeople()
        lst = []
        for pers in allPeople:
            lst.append(pers.get_id())
        toDelete = self.findPerson(lst, id, 0)
        if toDelete == -1:
            print('No such person in the list!')
        else:
            self.__repo.deletePersWithId(toDelete)


    def findPerson(self, lst, id, i):
        '''
        Metoda recursiva
        :param lst:
        :param id:
        :param i:
        :return:
        '''
        if i >= len(lst):
            return -1
        if lst[i] == id:
            return lst[i]
        return self.findPerson(lst, id, i+1)


    def printPers(self, id):
        """
        :param id: int
        :return: a single person
        """
        return self.__repo.findPerson(id)

    def searchInPerson(self, p, secv):
        name = p.get_name()
        adress = p.get_adress()
        if secv in name:
            return True
        if secv in adress:
            return True
        return False
