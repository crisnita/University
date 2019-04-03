"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   10/26/2018 15:47
"""


from utils.solve import *


def ui():
    """
    Creaza consola si il lasa pe utilizator sa isi aleaga operatia dorita

    in: NONE
    pre: NONE
    out: nrCerinta, nrLit
    post: nrCerinta = int, nrLit = char si sunt corespunzatoare

    """

    nrCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

1. Adaugare
2. Stergere
3. Cautari
4. Rapoarte
5. Filtru
6. Undo the last operation    
    ''')
    try:
        nrCerinta = int(nrCerinta)

        if nrCerinta == 1:
            litCerinta = input('''
INRTODUCETI LITERA CORESPUNZATOARE OPERATIEI DORITE:

a. adaugă cheltuială pentru un apartament
b. modifică cheltuială
        ''')
            try:
                if litCerinta == 'a' or litCerinta =='b':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        if nrCerinta == 2:
            litCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

a. Șterge toate cheltuielile de la un apartament
b. Șterge cheltuielile de la apartamente consecutive (Ex. se dau două numere de
apartament 2 și 5 și se șterg toate cheltuielile de la apartamentele 1,2,3,4 și 5)
c. Șterge cheltuielile de un anumit tip de la toate apartamentele
            ''')
            try:
                if litCerinta == 'a' or litCerinta =='b' or litCerinta =='c':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        if nrCerinta == 3:
            litCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

a. Tipărește toate apartamentele care au cheltuieli mai mari decât o sumă dată
b. Tipărește cheltuielile de un anumit tip de la toate apartamentele
c. Tipărește toate cheltuielile efectuate înainte de o zi și mai mari decât o sumă (se dă suma
și ziua)
            ''')
            try:
                if litCerinta == 'a' or litCerinta == 'b' or litCerinta == 'c':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        if nrCerinta == 4:
            litCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

a. Tipărește suma totală pentru un tip de cheltuială
b. Tipărește toate apartamentele sortate după un tip de cheltuială
c. Tipărește totalul de cheltuieli pentru un apartament dat
            ''')
            try:
                if litCerinta == 'a' or litCerinta == 'b' or litCerinta == 'c':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        if nrCerinta == 5:
            litCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

a. Elimină toate cheltuielile de un anumit tip
b. Elimină toate cheluielile mai mici decât o sumă dată
            ''')
            try:
                if litCerinta == 'a' or litCerinta == 'b' or litCerinta == 'c':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        if nrCerinta == 6:
            litCerinta = input('''
INTRODUCETI NUMARUL OPERATIEI DORITE:

a. Reface ultima operație (lista de cheltuieli revine la ce exista înainte de ultima operație care
a modificat lista)
            ''')
            try:
                if litCerinta == 'a' or litCerinta == 'b' or litCerinta == 'c':
                    return nrCerinta, litCerinta
                else:
                    print('Litera gresita')
                    return 0, 0
            except:
                print('Litera gresita')
                return 0, 0

        else:
            print('Nu ati introdus un numar corespunzator')
            return 0, 0
    except:
        print('Nu ati introdus un numar corespunzator')
        return 0, 0


def solve(nrCerinta, litCerinta, vect):
    '''
    redirectioneaza programul inspre metodele corespunzatoare lui nrCerinta si litCerinta

    in: nrCerinta, litCerinta
    pre: parametri sunt int si char
    out: NONE
    post: NONE
    '''
    if nrCerinta == 1:
        if litCerinta == 'a':
            print('Introduceti numarul apartamentului, suma si tipul cheltuielii:')
            nrApartament, suma, tip = input().split()
            return solve_1a(vect,nrApartament,suma,tip)
        else:
            if vect == []:
                print('Vectorul este gol, nu avem ce sa modificam')
                return vect
            else:
                print('Introduceti numarul cheltuielii pe care vreti sa o modificati, suma si tipul ei:')
                nrCheltuiala, suma, tip = input().split()
                if nrCheltuiala>len(vect):
                    print('Nu avem atatea cheltuieli')
                    return vect
                return solve_1b(vect,nrCheltuiala,suma,tip)
    elif nrCerinta == 2:
        if litCerinta == 'a':
            ap = input('Introduceti numarul apartamentului: ')
            return solve_2a(vect,ap)
        elif litCerinta == 'b':
            nr1,nr2 = input('Introduceti cele doua numere ce reprezinta capatele intervalului: ').split()
            return solve_2b(vect,nr1,nr2)
        else:
            tip = input('Introduceti tipul cheltuielilor care sa fie sterse: ')
            return solve_2c(vect,tip)
    elif nrCerinta == 3:
        if litCerinta == 'a':
            sum = input('Introduceti o suma:')
            return solve_3a(vect,sum)
        elif litCerinta == 'b':
            tip = input('Introduceti tipul cheltuielii:')
            return solve_3b(vect,tip)
        else:
            zi, suma = input('Introduceti o zi si o suma: ').split()
            return solve_3c(vect,zi,suma)
    elif nrCerinta == 4:
        if litCerinta == 'a':
            tip = input('Introduceti tipul cheltuielii')
            return solve_4a(vect,tip)
        elif litCerinta == 'b':
            return solve_4b(vect)
        else:
            ap = input('Dati un apartament:')
            return solve_4c(vect,ap)
    elif nrCerinta == 5:
        if litCerinta == 'a':
            tip = input('Introduceti tipul cheltuielii:')
            return solve_5a(vect,tip)
        elif litCerinta == 'b':
            sum = input('Introduceti o suma:')
            return solve_5b(vect,sum)
