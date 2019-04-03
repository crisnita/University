"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   10/20/2018 14:24
"""


#from domain.uiMethod import *
from domain.newUI import *
from Tests.tests import test
from utils.solve import undo
from copy import deepcopy
from utils.getThings import *

'''Varianta buna'''
'''def run():
    vect = []
    vaux = []
    vect2 = []
    while True:
        nrCerinta, litCerinta = ui()
        if nrCerinta != 0 and nrCerinta != 6:
            if litCerinta.isdigit() == False:
                vect = solve(nrCerinta,litCerinta,vect)
                vaux.append(deepcopy(vect))
                print(vect)
                print(vaux)

        elif nrCerinta == 6:
            vect,vaux = undo(vect,vaux)'''


def run():
    vect = []
    vaux = []
    lst = []
    lst = citire()
    while lst:
        nrCerinta, litCerinta = ui2(lst)
        if int(nrCerinta) != 6:
            vect,lst = solve2(nrCerinta,litCerinta,vect,lst)
            vaux.append(deepcopy(vect))

        elif int(nrCerinta) == 6:
            del lst[0:2]
            vect,vaux = undo(vect,vaux)
        print(vect)
        #print(vaux)
    #print(lst)
    #print(vect)

test()
run()