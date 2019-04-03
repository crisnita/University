"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 11:24
"""
from domain.entities import Melodie


class RepositoryMuzica:
    def __init__(self):
        self.__lst = self.__loadFromFile()

    def getAll(self):
        '''
        returns all the elements from repository
        :return:
        '''
        return self.__lst

    def modMelodie(self, melodie):
        '''
        modifica melodia in repository
        :param melodie:
        :return:
        '''
        for i in range(len(self.__lst)):
            if self.__lst[i].get_titlu() == melodie.get_titlu() and self.__lst[i].get_artist() == melodie.get_artist():
                self.__lst[i] = melodie
                self.__saveInFile(self.__lst)

    def load(self):
        self.__lst = self.__loadFromFile()

    def __loadFromFile(self):
        '''
        loads everything from file
        :return:
        '''
        try:
            f = open("repository/melodii.txt", "r")
        except IOError:
            print("Nu am putut deschide fisierul!")
            return []
        line = f.readline().strip()
        content = []
        while line != "":
            attrs = line.split(", ")
            m = Melodie(attrs[0], attrs[1], attrs[2], attrs[3])
            content.append(m)
            line = f.readline().strip()
        f.close()
        return content

    def __saveInFile(self, melodii):
        '''
        saves everything in file
        :param melodii:
        :return:
        '''
        with open("repository/melodii.txt", "w") as f:
            for melodie in melodii:
                m = melodie.get_titlu() + ", " + melodie.get_artist() + ", " + melodie.get_gen() + ", " + melodie.get_durata() \
                                                                                                        + '\n'
                f.write(m)

    def addMelodie(self, melodie):
        '''
        adauga o melodie in lista. salveaza dupa aceea datele in fisier
        :param melodie:
        :return:
        '''
        self.__lst.append(melodie)
        self.__saveInFile(self.__lst)
        return len(self.__lst)
