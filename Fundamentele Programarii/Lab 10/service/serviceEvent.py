"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/19/2018 14:20
"""
from domain.entities import Event


class ServiceEvent:
    def __init__(self, repo, val):
        self.__repo = repo
        self.__val = val

    def createEvent(self, id, date, time, descr):
        """
        1) Create event
        2) Validate event
        3) Store event in repository
        :param id:
        :param date:
        :param time:
        :param descr:
        :return:
        """
        e = Event(id, date, time, descr)
        self.__val.validateEvent(e)
        self.__repo.storeElem(e)
        return e

    def getAllEvents(self):
        return self.__repo.getAllEvents()

    def modEvent(self, id, date, time, descr):
        event = Event(id, date, time, descr)
        self.__repo.update(event)

    def deleteEventFaraRecursivitate(self, id):
        allEvents = self.__repo.getAllEvents()
        for e in allEvents:
            if e.get_id() == id:
                self.__repo.deleteEvent(e)

    def deleteEvent(self, id):
        allPeople = self.__repo.getAllEvents()
        lst = []
        for pers in allPeople:
            lst.append(pers.get_id())
        toDelete = self.findEvent(lst, id, 0)
        if toDelete == -1:
            print('No such event in the list!')
        else:
            self.__repo.deleteEventWithId(toDelete)


    def findEvent(self, lst, id, i):
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
        return self.findEvent(lst, id, i+1)

    def printEve(self, id):
        return self.__repo.findEvent(id)

    def searchInEvent(self, e, secv):
        date = e.get_date()
        time = e.get_time()
        descr = e.get_descr()
        if secv in date:
            return True
        if secv in time:
            return True
        if secv in descr:
            return True
        return False

    def loadEve(self):
        self.__repo.load()

    def saveEve(self):
        self.__repo.save()
