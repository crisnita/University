"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/22/2018 19:51
"""
from domain.entities import *


class ServiceEnroll:
    def __init__(self, repPers, repEvent, repEnroll):
        self.__repPers = repPers
        self.__repEvent = repEvent
        self.__repEnroll = repEnroll

    def enroll(self, p, e):
        """
        enrolls a person to an event
        :param p1:
        :param p2:
        :return:
        """
        pair = PairID(p, e)
        self.__repEnroll.addPair(pair)

    def getAllPairs(self):
        return self.__repEnroll.getAllPairs()

    def sortEv(self, id):
        '''
        Prepares a list to be sorted. Uses sorting methods
        :param id:
        :return:
        '''
        lst = self.__repEnroll.getAllPairsWithID(id)    # avem o lista cu id-urile evenimentelor
        for i in range(len(lst)):
            lst[i] = self.__repEvent.findEvent(lst[i])
        lst2 = []
        for i in range(len(lst)):
            lst2.append([lst[i].get_id(), lst[i].get_date(), lst[i].get_time(), lst[i].get_descr()])
        return self.shakeSort(lst2, reverse=True, key=lambda x: x[3])

    def swap(self, lst, a, b):
        '''
        swaps two elements of a list of lists
        :param lst:
        :param a:
        :param b:
        :return:
        '''
        aux = lst[a]
        lst[a] = lst[b]
        lst[b] = aux
        return lst

    def selectionSort(self, lst, key=lambda x: x[3], reverse=False):
        '''
        This applies the simple selection sort on a list. Receives a list and returns the sorted list
        :param lst:
        :param key:
        :param reverse:
        :return:
        '''
        for firstElem in range(len(lst) - 1):
            minim = firstElem
            for i in range(firstElem + 1, len(lst)):
                if key(lst[i]) < key(lst[minim]):
                    minim = i
            if minim != firstElem:
                self.swap(lst, minim, firstElem)

        if reverse == True:
            for i in range(len(lst) // 2):
                aux = lst[i]
                lst[i] = lst[len(lst) - i - 1]
                lst[len(lst) - i - 1] = aux

        return lst

    def shakeSort(self, lst, key=lambda x: x[3], reverse=False):
        '''
        Complexitate:

        Worst case: In cazul in care toate cele n elementele sunt in ordine inversa, vom avea nevoie de n/2 parcurgeri la
        dreapta si n/2 la stanga, in total n. Ceea ce inseamna ca vom avea n*n = n^2 cazuri => O(n^2)

        Medium case: Daca jumatate din lista e bine sortata, iar cealalt are termeni mai mare care trebuie sortati, avem
        un numar de n/2 * n/2 operatii, cane ne da Teta(n^2)

        Best case: In cazul in care toate cele n elemente sunt aranjate in ordinea buna, tot vom avea nevoie de o
        parcurgere a listei, asadar n operatii => Omega(n)
        :param lst:
        :param key:
        :param reverse:
        :return:
        '''
        lun = len(lst)
        start = 0
        end = lun - 1
        swapped = True
        while swapped is True:
            swapped = False
            for i in range(start, end):
                if key(lst[i]) > key(lst[i + 1]):
                    lst[i], lst[i + 1] = lst[i + 1], lst[i]  # swaps the items
                    swapped = True
            if swapped is False:
                break

            swapped = False
            end = end - 1
            for i in range(end, start, -1):
                if key(lst[i]) < key(lst[i - 1]):
                    lst[i], lst[i - 1] = lst[i - 1], lst[i]
                    swapped = True
            if swapped is False:
                break

            start = start + 1

        if reverse is True:
            for i in range(lun // 2):
                lst[i], lst[lun - i - 1] = lst[lun - i - 1], lst[i]
        return lst

    def sortList(self, lst):
        return sorted(lst, key=lambda x: x[3])

    def theMostEvents(self):
        maxim = 0
        lst = self.__repEnroll.getAllPairs()
        contor = []
        final = []
        for i in range(200):
            contor.append(0)
        for pair in lst:
            contor[int(pair.get_p())] += 1
            if contor[int(pair.get_p())] > maxim:
                maxim = contor[int(pair.get_p())]
        for i in range(len(contor)):
            if contor[i] == maxim:
                final.append(i)
        return final

    def loadEnr(self):
        self.__repEnroll.load()

    def saveEnr(self):
        self.__repEnroll.save()

    def theMostParticipants(self):
        maxim = 0
        lst = self.__repEnroll.getAllPairs()
        contor = []
        vect = []
        for i in range(200):
            contor.append(0)
        for pair in lst:
            contor[int(pair.get_e())] += 1
        for i in range(len(contor)):
            if contor[i] != 0:
                vect.append((i, contor[i]))
        vect.sort(key=lambda tup: tup[1], reverse=True)
        nrToShow = int(len(vect) / 5)
        if nrToShow == 0:
            nrToShow = 1
        if nrToShow != len(vect):
            for i in range(nrToShow, len(vect)):
                del vect[i]
        return vect





    '''def personsEvents(self, id):
        return self.__repo.getAllPairsWithID(id)

    def theMostEvents(self):
        maxim = 0
        lst = self.__repo.getAllPairs()
        contor = []
        final = []
        for i in range(200):
            contor.append(0)
        for pair in lst:
            contor[int(pair.get_p())] += 1
            if contor[int(pair.get_p())] > maxim:
                maxim = contor[int(pair.get_p())]
        for i in range(len(contor)):
            if contor[i] == maxim:
                final.append(i)
        return final

    def theMostParticipants(self):
        maxim = 0
        lst = self.__repo.getAllPairs()
        contor = []
        vect = []
        for i in range(200):
            contor.append(0)
        for pair in lst:
            contor[int(pair.get_e())] += 1
        for i in range(len(contor)):
            if contor[i] != 0:
                vect.append((i, contor[i]))
        vect.sort(key = lambda tup: tup[1], reverse = True)
        nrToShow = int(len(vect)/5)
        if nrToShow == 0:
            nrToShow = 1
        if nrToShow != len(vect):
            for i in range(nrToShow, len(vect)):
                del vect[i]
        return vect

    def raport1(self):
        tot = 0
        contor = []
        for i in range(200):
            contor.append(0)
        lst = self.__repo.getAllPairs()
        for pair in lst:
            contor[int(pair.get_p())] = 1
        for i in range(len(contor)):
            if contor[i] == 1:
                tot += 1
        return tot

    def raport2(self):
        tot = 0
        contor = []
        for i in range(200):
            contor.append(0)
        lst = self.__repo.getAllPairs()
        for pair in lst:
            contor[int(pair.get_e())] = 1
        for i in range(len(contor)):
            if contor[i] == 1:
                tot += 1
        return tot

    def raport3(self):
        return len(self.__repo.getAllPairs())

    def raport4(self, lstPeople):
        vect = []
        lst = self.__repo.getAllPairs()
        contor = []
        for i in range(200):
            contor.append(0)
        for pair in lst:
            contor[int(pair.get_p())] = 1
        for i in range(len(contor)):
            if contor[i] == 1:
                for j in lst:
                    if j.get_p() == i:
                        contor[i] = 0
        for i in range(len(contor)):
            if contor[i] == 1:
                vect.append(i)
        for i in range(len(lstPeople)):
            lstPeople[i] = int(lstPeople[i])
        for i in vect:
            lstPeople.remove(i)
        return lstPeople'''
