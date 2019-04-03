"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/6/2018 08:10
"""


from utils.solve import *


def citire():
    text = input()
    lst = text.split()
    return lst


def ui2(lst):
    nrCerinta,litCerinta = lst[0:2]
    return nrCerinta,litCerinta


def solve2(nrCerinta,litCerinta,vect,lst):
    if nrCerinta == '1':
        if litCerinta == 'a':
            nrApartament, suma, tip = lst[2:5]
            del lst[0:5]
            return solve_1a(vect, nrApartament, suma, tip),lst
        elif litCerinta == 'b':
            nrCheltuiala, suma, tip = lst[2:5]
            del lst[0:5]
            return solve_1b(vect, nrCheltuiala, suma, tip),lst
    elif nrCerinta == '2':
        if litCerinta == 'a':
            ap = lst[2]
            del lst[0:3]
            return solve_2a(vect, ap),lst
        elif litCerinta == 'b':
            nr1, nr2 = lst[2:4]
            del lst[0:4]
            return solve_2b(vect, nr1, nr2),lst
        else:
            tip = lst[2]
            del lst[0:3]
            return solve_2c(vect, tip),lst
    elif nrCerinta == '3':
        if litCerinta == 'a':
            sum = lst[2]
            del lst[0:3]
            return solve_3a(vect, sum),lst
        elif litCerinta == 'b':
            tip = lst[2]
            del lst[0:3]
            return solve_3b(vect, tip),lst
        else:
            zi, suma = lst[2:4]
            del lst[0:4]
            return solve_3c(vect, zi, suma),lst
    elif nrCerinta == '4':
        if litCerinta == 'a':
            tip = lst[2]
            del lst[0:3]
            return solve_4a(vect, tip),lst
        elif litCerinta == 'b':
            del lst[0:2]
            return solve_4b(vect),lst
        else:
            ap = lst[2]
            del lst[0:3]
            return solve_4c(vect, ap),lst
    elif nrCerinta == '5':
        if litCerinta == 'a':
            tip = lst[2]
            del lst[0:3]
            return solve_5a(vect, tip),lst
        elif litCerinta == 'b':
            sum = lst[2]
            del lst[0:3]
            return solve_5b(vect, sum),lst



'''
    def solve(nrCerinta, litCerinta, vect):
        redirectioneaza programul inspre metodele corespunzatoare lui nrCerinta si litCerinta

        in: nrCerinta, litCerinta
        pre: parametri sunt int si char
        out: NONE
        post: NONE
        
        if nrCerinta == 1:
            if litCerinta == 'a':
                print('Introduceti numarul apartamentului, suma si tipul cheltuielii:')
                nrApartament, suma, tip = input().split()
                return solve_1a(vect, nrApartament, suma, tip)
            else:
                if vect == []:
                    print('Vectorul este gol, nu avem ce sa modificam')
                    return vect
                else:
                    print('Introduceti numarul cheltuielii pe care vreti sa o modificati, suma si tipul ei:')
                    nrCheltuiala, suma, tip = input().split()
                    if nrCheltuiala > len(vect):
                        print('Nu avem atatea cheltuieli')
                        return vect
                    return solve_1b(vect, nrCheltuiala, suma, tip)
        elif nrCerinta == 2:
            if litCerinta == 'a':
                ap = input('Introduceti numarul apartamentului: ')
                return solve_2a(vect, ap)
            elif litCerinta == 'b':
                nr1, nr2 = input('Introduceti cele doua numere ce reprezinta capatele intervalului: ').split()
                return solve_2b(vect, nr1, nr2)
            else:
                tip = input('Introduceti tipul cheltuielilor care sa fie sterse: ')
                return solve_2c(vect, tip)
        elif nrCerinta == 3:
            if litCerinta == 'a':
                sum = input('Introduceti o suma:')
                return solve_3a(vect, sum)
            elif litCerinta == 'b':
                tip = input('Introduceti tipul cheltuielii:')
                return solve_3b(vect, tip)
            else:
                zi, suma = input('Introduceti o zi si o suma: ').split()
                return solve_3c(vect, zi, suma)
        elif nrCerinta == 4:
            if litCerinta == 'a':
                tip = input('Introduceti tipul cheltuielii')
                return solve_4a(vect, tip)
            elif litCerinta == 'b':
                return solve_4b(vect)
            else:
                ap = input('Dati un apartament:')
                return solve_4c(vect, ap)
        elif nrCerinta == 5:
            if litCerinta == 'a':
                tip = input('Introduceti tipul cheltuielii:')
                return solve_5a(vect, tip)
            elif litCerinta == 'b':
                sum = input('Introduceti o suma:')
                return solve_5b(vect, sum)
'''