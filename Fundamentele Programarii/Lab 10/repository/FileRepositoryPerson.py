"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/17/2018 18:14
"""
from domain.entities import Person


class ExceptionRepoP(Exception):
    pass

class FileRepositoryPerson:
    def __init__(self):
        self.__lst = self.__loadFromFile()

    def __loadFromFile(self):
        try:
            f = open("repository/persons.txt", "r")
        except IOError:
            print("Couldn't open file!")
            return {}
        line = f.readline().strip()
        content = {}
        while line != "":
            attrs = line.split("|")
            st = Person(attrs[0], attrs[1], attrs[2])
            content[attrs[0]] = st
            line = f.readline().strip()
        f.close()
        return content

    def __saveInFile(self, persons):
        with open("repository/persons.txt", "w") as f:
            for person in persons.values():
                s = str(person.get_id()) + "|" + person.get_name() + "|" + person.get_adress() + "\n"
                f.write(s)

    def load(self):
        self.__lst = self.__loadFromFile()

    def save(self):
        self.__saveInFile(self.__lst)


    def getAllPeople(self):
        self.__lst = self.__loadFromFile()
        return list(self.__lst.values())

    def storeElem(self, elem):
        if elem.get_id() in self.__lst:
            raise ExceptionRepoP()
        self.__lst[elem.get_id()] = elem
        self.__saveInFile(self.__lst)


    def update(self, pers):
        self.__lst[pers.get_id()] = pers
        self.__saveInFile(self.__lst)

    def deletePers(self, pers):
        del self.__lst[pers.get_id()]
        self.__saveInFile(self.__lst)

    def deletePersWithId(self, id):
        del self.__lst[id]
        self.__saveInFile(self.__lst)

    def findPerson(self, id):
        if id in self.__lst:
            return self.__lst[id]
        return None

    def clear_file(self):
        self.__saveInFile({})
        self.__lst = {}