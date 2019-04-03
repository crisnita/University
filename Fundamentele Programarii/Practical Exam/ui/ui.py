"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 11:05
"""
from domain.validator import ValidatorException


class ui:
    def __init__(self, servMuz):
        self.__servMuz = servMuz

    def __addMelodie(self):
        '''
        primeste titlu, artist, gen si durata si le trimite catre service pentru a adauga
        :return:
        '''
        titlu = input("Dati titlul: ")
        artist = input("Dati artistul: ")
        gen = input("Dati genul: ")
        durata = input("Dati durata: ")
        try:
            melodie = self.__servMuz.addMelodie(titlu, artist, gen, durata)
        except ValidatorException as err:
            print(err)

    def __modMelodie(self):
        '''
        primeste titlu, artist, gen si durata si le trimite catre service pentru a modifica
        :return:
        '''
        titlu = input("Dati titlul: ")
        artist = input("Dati artistul: ")
        gen = input("Dati genul: ")
        durata = input("Dati durata: ")
        try:
            gasit = self.__servMuz.modMelodie(titlu, artist, gen, durata)
            if gasit == False:
                print("Nu am gasit o melodie cu atributele acestea!")
        except ValidatorException as err:
            print(err)

    def __addRandom(self):
        '''
        ii comanda service-ului sa creeze un numar de melodii random
        :return:
        '''
        nrMelodii = input("Dati numarul de melodii: ")
        try:
            nrMelodii = self.__servMuz.addRandom(nrMelodii)
        except:
            print("Date gresite!")

    def __export(self):
        file_name = input("Give a file name: ")
        self.__servMuz.export(file_name)

    def show_ui(self):
        '''
        Preia comenzile din consola. Redirectioneaza programul
        :return:
        '''
        while True:
            cmd = input("Dati o comanda: ")
            self.__servMuz.load()
            if cmd.upper() == "EXIT":
                return
            elif cmd.upper() == "ADD":
                self.__addMelodie()
            elif cmd.upper() == "MOD":
                self.__modMelodie()
            elif cmd.upper() == "RANDOM":
                self.__addRandom()
            elif cmd.upper() == "EXPORT":
                self.__export()
            else:
                print("Comanda invalida!")