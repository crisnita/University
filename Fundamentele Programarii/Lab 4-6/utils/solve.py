"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   10/26/2018 16:41
"""

from utils.getThings import *
from copy import deepcopy


def interschimba(a, b):
    """
    :param a: int
    :param b: int
    :return: returneaza pe a si b, in ordine crescatoare
    """
    if a > b:
        aux = a
        a = b
        b = aux
    return a, b


def solve_1a(vect, nrApartament, suma, tip):
    """
    :param vect: list
    :param nrApartament: int
    :param suma: int
    :param tip: str
    :return: returneaza vectorul modificat, dupa ce s-a adaugat o cheltuiala
    """
    try:
        nrApartament = int(nrApartament)
        suma = int(suma)
        elem = creeazaApartament(nrApartament, suma, tip)
        vect.append(elem)
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_1b(vect, nrCheltuiala, suma, tip):
    """
    :param vect: list
    :param nrCheltuiala: int
    :param suma: int
    :param tip: str
    :return: returneaza veectorul modificat, dupa ce s-a modificat o cheltuiala
    """
    try:
        suma = int(suma)
        nrCheltuiala = int(nrCheltuiala)
        if nrCheltuiala + 1 > len(vect):
            print('Nu avem destule elemente in sir')
            return vect
        else:
            suma = int(suma)
            ap = getApartament(vect, nrCheltuiala)
            vect[nrCheltuiala] = creeazaApartament(ap, suma, tip)
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_2a(vect, ap):
    """
    :param vect: list
    :param ap: int
    :return: returneaza vectorul dupa ce s-au sters toate cheltuielile de un anumit tip
    """
    try:
        ap = int(ap)
        i = 0
        while i < len(vect):
            if getApartament(vect, i) == ap:
                del vect[i]
            else:
                i = i + 1
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_2b(vect, nr1, nr2):
    """
    :param vect: list
    :param nr1: int
    :param nr2: int
    :return: returneaza vectorul dupa ce s-au sters toate cheltuielile de la apartamentele cuprinse intre nr1 si nr2
    """
    try:
        nr1, nr2 = interschimba(nr1, nr2)
        nr1 = int(nr1)
        nr2 = int(nr2)
        i = 0
        while i < len(vect):
            if nr1 <= getApartament(vect, i) <= nr2:
                del vect[i]
            else:
                i = i + 1
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_2c(vect, tip):
    """
    :param vect: list
    :param tip: str
    :return: returneaza vectorul dupa ce s-au sters toate cheltuielile de un anumit tip de la toate apartamentele
    """
    try:
        i = 0
        tip = str(tip)
        while i < len(vect):
            if getType(vect, i) == tip:
                del vect[i]
            else:
                i = i + 1
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_3a(vect, sum):
    """
    :param vect: list
    :param sum: int
    :return: returneaza vect dupa ce s-au tiparit toate apartamentele care au cheltuieli mai mari decât o sumă data
    """
    try:
        sum = int(sum)
        for i in range(len(vect)):
            if getSum(vect, i) > sum:
                print(vect[i])
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_3b(vect, tip):
    """
    :param vect: list
    :param tip: str
    :return: returneaza vect dupa ce s-au tiparit toate cheltuielile de un anumit tip de la toate apartamentele
    """
    try:
        tip = str(tip)
        for i in range(len(vect)):
            if getType(vect, i) == tip:
                print(vect[i])
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_3c(vect, zi, suma):
    """
    :param vect: list
    :param zi: int
    :param suma: int
    :return: returneaza vect dupa ce s-au tiparit toate cheltuielile inainte de o zi si mai mari decat o suma
    """
    try:
        zi = int(zi)
        suma = int(suma)
        if len(vect) == 0:
            print('Vectorul este gol!')
        else:
            if zi > len(vect):
                zi = len(vect)
            for i in range(zi):
                if getSum(vect, i) > suma:
                    print(vect[i])
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_4a(vect, tip):
    """
    :param vect: list
    :param tip: str
    :return: returneaza vect dupa ce s-a tiparit suma totala pentru un tip de cheltuieli
    """
    try:
        tip = str(tip)
        sum = 0
        for i in range(len(vect)):
            if getType(vect, i) == tip:
                sum = sum + getSum(vect, i)
        print(sum)
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_4b(vect):
    """
    :param vect: list
    :return: returneaza vect dupa ce s-au afisat toate apartamentele sortate alfabetic dupa tip
    """
    vaux = sorted(vect, key=lambda x: x[2])
    print(vaux)
    return vect


def solve_4c(vect, ap):
    """
    :param vect: list
    :param ap: int
    :return: returneaza vect dupa ce s-a tiparit totalul de cheltuieli pentru un apartament dat
    """
    try:
        ap = int(ap)
        sum = 0
        for i in range(len(vect)):
            print(getApartament(vect, i))
            if getApartament(vect, i) == ap:
                sum = sum + getSum(vect, i)
        print(sum)
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_5a(vect, tip):
    """
    :param vect: list
    :param tip: str
    :return: returneaza vect dupa ce s-au eliminat toate cheltuielile de un anumit tip
    """
    try:
        i = 0
        tip = str(tip)
        while i < len(vect):
            if getType(vect, i) == tip:
                del vect[i]
            else:
                i = i + 1
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def solve_5b(vect, sum):
    """
    :param vect: list
    :param sum: int
    :return: returneaza vect dupa ce s-au eliminat toate cheltuielile mai mici decat o suma data
    """
    try:
        i = 0
        sum = int(sum)
        while i < len(vect):
            if getSum(vect, i) < sum:
                del vect[i]
            else:
                i = i + 1
    except:
        print('Eroare: date necorespunzatoare')
    return vect


def undo(vect, vaux):
    """
    :param vect: list
    :param vaux: list
    :return: returneaza noile liste, dupa ce vect s-a dat cu un pas inapoi
    """
    if len(vaux) >= 2:
        vaux.pop()
        vect = deepcopy(vaux[-1])
    elif len(vaux) == 1:
        vaux = []
        vect = []
    #print('undo')
    #print(vect)
    #print(vaux)
    return vect, vaux
