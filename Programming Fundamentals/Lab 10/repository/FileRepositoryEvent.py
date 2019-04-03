"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/19/2018 14:20
"""
from domain.entities import Event


class ExceptionRepoE(Exception):
    pass

class FileRepositoryEvent:
    def __init__(self):
        self.__lst = self.__loadFromFile()

    def __loadFromFile(self):
        try:
            f = open("repository/events.txt", "r")
        except IOError:
            print("Couldn't open file!")
            return {}
        line = f.readline().strip()
        content = {}
        while line != "":
            attrs = line.split("|")
            st = Event(attrs[0], attrs[1], attrs[2], attrs[3])
            content[attrs[0]] = st
            line = f.readline().strip()
        f.close()
        return content

    def load(self):
        self.__lst = self.__loadFromFile()

    def __saveInFile(self, events):
        with open("repository/events.txt", "w") as f:
            for event in events.values():
                s = str(event.get_id()) + "|" + event.get_date() + "|" + event.get_time() + "|" + event.get_descr() + "\n"
                f.write(s)

    def storeElem(self, elem):
        if elem.get_id() in self.__lst:
            raise ExceptionRepoE()
        self.__lst[elem.get_id()] = elem
        self.__saveInFile(self.__lst)

    def getAllEvents(self):
        return list(self.__lst.values())

    def update(self, event):
        self.__lst[event.get_id()] = event
        self.__saveInFile(self.__lst)

    def deleteEvent(self, e):
        del self.__lst[e.get_id()]
        self.__saveInFile(self.__lst)

    def findEvent(self, id):
        if id in self.__lst:
            return self.__lst[id]
        return None

    def deleteEventWithId(self, id):
        del self.__lst[id]
        self.__saveInFile(self.__lst)

    def clear_file(self):
        self.__saveInFile({})
        self.__lst = {}

    def save(self):
        self.__saveInFile(self.__lst)