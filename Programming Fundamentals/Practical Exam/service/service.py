"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 11:08
"""
from domain.entities import Melodie
import random


class ServiceMuzica:
    def __init__(self, valMuz, repoMuz):
        self.__valMuz = valMuz
        self.__repoMuz = repoMuz


    def load(self):
        self.__repoMuz.load()

    def addMelodie(self, titlu, artist, gen, durata):
        '''
        Primeste un titlu, un artist, genul si durata. Creeaza un obiect de tip Melodie. Daca sunt date necorespunzatoare,
        elementul nu se mai adauga si se va afisa din consola un mesaj de eroare. Returneaza melodia in cazul in care
        a fost creata si bagata in lista
        :param titlu:
        :param artist:
        :param gen:
        :param durata:
        :return: obiect tip Melodie
        '''
        melodie = Melodie(titlu, artist, gen, durata)
        self.__valMuz.validate(melodie)
        self.__repoMuz.addMelodie(melodie)
        return melodie

    def modMelodie(self, titlu, artist, gen, durata):
        '''
        Primeste titlu, artrist, genul si durata. Creeaza un obiect de tip Melodie. Daca sunt date necorespunzatoare,
        elementul nu se mai adauga si se va afisa din consola un mesaj de eroare. De asemenea, daca nu exista deja o
        melodie cu numele si artistul respectiv, se afiseaza un mesaj de eroare. Altfel, modifica genul si durata
        melodiei existente
        :param titlu:
        :param artist:
        :param gen:
        :param durata:
        :return: obiect tip Melodie
        '''
        melodie = Melodie(titlu, artist, gen, durata)
        self.__valMuz.validate(melodie)
        lst = self.__repoMuz.getAll()
        gasit = False
        for elem in lst:
            if elem.get_titlu() == titlu and elem.get_artist() == artist:
                gasit = True
                self.__repoMuz.modMelodie(melodie)
        return gasit


    def __titlu_random(self):
        '''
        returneaza un titlu generat random, care este format din doua cuvinte separate prin spatiu, in care consoanele
        si vocalele alterneaza
        :return:
        '''
        titlu = ""
        vocale = ['a', 'e', 'i', 'o', 'u']
        consoane = ['b', 'c', 'd', 'f', 'g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']
        c = vocale[random.randint(0, len(vocale)-1)]
        titlu += c

        c = consoane[random.randint(0, len(consoane)-1)]
        titlu += c

        c = vocale[random.randint(0, len(vocale) - 1)]
        titlu += c

        titlu += " "

        c = consoane[random.randint(0, len(consoane) - 1)]
        titlu += c

        c = vocale[random.randint(0, len(vocale) - 1)]
        titlu += c

        c = consoane[random.randint(0, len(consoane) - 1)]
        titlu += c

        c = vocale[random.randint(0, len(vocale) - 1)]
        titlu += c

        c = consoane[random.randint(0, len(consoane) - 1)]
        titlu += c

        return titlu


    def __gen_random(self):
        '''
        returneaza un gen muzical aleator ales din: Rock, Pop, Jazz, Altele
        :return:
        '''
        genuri = ["Rock", "Pop", "Jazz", "Altele"]
        gen = genuri[random.randint(0, 3)]
        return gen

    def __durata_random(self):
        '''
        returneaza o data random de la 1 la 500
        :return:
        '''
        durata = random.randint(1,500)

    def addRandom(self, nrMelodii):
        '''
        creeaza un numar de melodii random, care vor fi mai apoi trimise catre repository
        :param nrMelodii:
        :return:
        '''
        for i in range(int(nrMelodii)):
            titlu = str(self.__titlu_random())
            artist = str(self.__titlu_random())
            gen = str(self.__gen_random())
            durata = str(self.__durata_random())

            melodie = Melodie(titlu, artist, gen, durata)
            self.__repoMuz.addMelodie(melodie)
        return nrMelodii

    def export(self, file_name):
        '''
        deschide fisierul sau, daca nu exista, il creeaza. Dupa care ia toate datele din repo si le incarca in acesta
        :param file_name:
        :return:
        '''
        try:
            name = "repository/" + file_name + ".csv"
            g = open(name, "x")
        except:
            pass
            #g = open("reposotory/" + file_name + ".csv", "w")

        lst = self.__repoMuz.getAll()

        sortat = False # sortare dupa artist
        while sortat == False:
            sortat = True
            for i in range(len(lst)-1):
                if lst[i].get_artist() > lst[i+1].get_artist():
                    lst[i], lst[i+1] = lst[i+1], lst[i]
                    sortat = False

        sortat = False # sortare dupa titlu
        while sortat == False:
            sortat = True
            for i in range(len(lst) - 1):
                if (lst[i].get_artist() == lst[i + 1].get_artist()) and (lst[i].get_titlu() > lst[i+1].get_titlu()):
                    lst[i], lst[i + 1] = lst[i + 1], lst[i]
                    sortat = False


        for melodie in lst:
            m = melodie.get_titlu() + ", " + melodie.get_artist() + ", " + melodie.get_gen() + ", " + melodie.get_durata() \
                + '\n'
            g.write(m)
        g.close()