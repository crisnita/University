"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/19/2018 14:20
"""
class ExceptionRepoE(Exception):
    pass

class RepositoryEvent:
    def __init__(self):
        self.__lst = {}

    def storeElem(self, elem):
        if elem.get_id() in self.__lst:
            raise ExceptionRepoE()
        self.__lst[elem.get_id()] = elem

    def getAllEvents(self):
        return list(self.__lst.values())

    def update(self, event):
        self.__lst[event.get_id()] = event

    def deleteEvent(self, e):
        del self.__lst[e.get_id()]

    def findEvent(self, id):
        if id in self.__lst:
            return self.__lst[id]
        return None
