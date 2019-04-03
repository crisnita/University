"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/9/2018 19:06
"""
from repository.repositoryPerson import ExceptionRepoP
from repository.repositoryEvent import ExceptionRepoE
from repository.repositoryEnroll import ExceptionRepoEnroll
from repository.FileRepositoryPerson import ExceptionRepoP
from repository.FileRepositoryEvent import ExceptionRepoE
from repository.FileRepositoryEnroll import ExceptionRepoEnroll
from domain.validators import ValidatorError
import random


class ui:
    def __init__(self, servicePpl, serviceEve, serviceEnr):
        self.__servicePpl = servicePpl
        self.__serviceEve = serviceEve
        self.__serviceEnr = serviceEnr

    def __addPerson(self):
        """
        Add person
        :return:
        """
        id = input('Give ID: ')
        name = input('Give name: ')
        adress = input('Give adress: ')

        try:
            person = self.__servicePpl.createPerson(id, name, adress)
        except ExceptionRepoP:
            print('Person already in the list!')
        except ValidatorError as err:
            print(err)

    def __addEvent(self):
        """
        Add event
        :return:
        """
        id = input('Give ID: ')
        date = input('Give date: ')
        time = input('Give time: ')
        descr = input('Give description: ')

        try:
            event = self.__serviceEve.createEvent(id, date, time, descr)
        except ExceptionRepoE:
            print('Event already in the list!')

    def __search(self):
        """
        Searches if a string appears in any persons/events and returns those entities
        :return:
        """
        secv = input('Give sequence: ')
        allPeople = self.__servicePpl.getAllPeople()
        allEvents = self.__serviceEve.getAllEvents()

        for p in allPeople:
            if self.__servicePpl.searchInPerson(p, secv) == True:
                print(p.get_id(), p.get_name(), p.get_adress())
        for e in allEvents:
            if self.__serviceEve.searchInEvent(e, secv) == True:
                print(e.get_id(), e.get_date(), e.get_time(), e.get_descr())

    def __sortEvents(self):
        id = input('Give person ID: ')
        lst = self.__serviceEnr.sortEv(id)
        for i in lst:
            print(*i)

    def __mostEvents(self):
        print(*self.__serviceEnr.theMostEvents())

    def __mostParticipants(self):
        tup = self.__serviceEnr.theMostParticipants()
        id = str(tup[0][0])
        nrPart = tup[0][1]
        descr = self.__serviceEve.printEve(id).get_descr()
        print(descr, nrPart)

    def __raportNouOLD(self):
        print('Numarul total de persoane este: ' + str(len(self.__servicePpl.getAllPeople())))
        print('Numarul total de evenimente este: ' + str(len(self.__serviceEve.getAllEvents())))
        print('Numarul total de asocieri este: ' + str(self.__serviceEnr.raport3()))
        print('Persoanele care nu sunt inscrise la niciun eveniment sunt: ')
        lstPeople = self.__servicePpl.getAllPeople()
        for i in range(len(lstPeople)):
            lstPeople[i] = lstPeople[i].get_id()
        lstPeople = self.__serviceEnr.raport4(lstPeople)
        #print(lstPeople)
        for i in range(len(lstPeople)):
            p = self.__servicePpl.printPers(str(lstPeople[i]))
            lstPeople[i] = (p.get_id(), p.get_name(), p.get_adress())
            print(lstPeople[i])

    def __printPeople(self):
        """
        Prints all people from the list
        :return:
        """
        allPeople = self.__servicePpl.getAllPeople()

        for p in allPeople:
            print(p.get_id(), p.get_name(), p.get_adress())

    def __printEvents(self):
        """
        Prints all events from the list
        :return:
        """
        allEvents = self.__serviceEve.getAllEvents()

        for e in allEvents:
            print(e.get_id(), e.get_date(), e.get_time(), e.get_descr())

    def __showEnrolled(self):
        allPairs = self.__serviceEnr.getAllPairs()

        for i in range(len(allPairs)):
            print(str(allPairs[i].get_p()) + ' ' + str(allPairs[i].get_e()))

    def __modifyPerson(self):
        """
        Receives the id of a person in order to modify it
        :return:
        """
        id = input('Give ID: ')
        name = input('Give a new name: ')
        adress = input('Give a new adress: ')
        self.__servicePpl.modPerson(id, name, adress)

    def __modifyEvent(self):
        """
        Receives the id of an event in order to modify it
        :return:
        """
        id = input('Give ID: ')
        date = input('Give date: ')
        time = input('Give time: ')
        descr = input('Give description: ')
        self.__serviceEve.modEvent(id, date, time, descr)

    def __delPerson(self):
        id = input('Give ID: ')
        self.__servicePpl.deletePerson(id)

    def __delEvent(self):
        id = input('Give ID: ')
        self.__serviceEve.deleteEvent(id)

    def __printPerson(self):
        id = input('Give ID: ')
        p = self.__servicePpl.printPers(id)
        print(p.get_id(), p.get_name(), p.get_adress())

    def __printEvent(self):
        id = input('Give ID: ')
        e = self.__serviceEve.printEve(id)
        print(e.get_id(), e.get_date(), e.get_time(), e.get_descr())

    def __enroll(self):
        p = input('Give the person ID: ')
        e = input('Give the event ID: ')
        try:
            int(p)
            int(e)
            self.__serviceEnr.enroll(p, e)
        except ExceptionRepoEnroll:
            print('Person already enrolled at this event! ')
        except:
            print('ID is not a number!')



    def show_ui(self):
        """
        make ui work
        :return:
        """

        self.addPeople()
        self.addEvents()

        while True:

            cmd = input("""
Give a command: 
ADD P, DEL P, MOD P, SHOW P, SHOW ALL P, MOST PARTICIPANTS,
ADD E, DEL E, MOD E, SHOW E, SHOW ALL E, MOST EVENTS,
SEARCH, ENROLL, SHOW ENROLLED, SORT EVENTS, RAPORT NOU, EXIT:
""")
            self.__servicePpl.loadPpl()
            self.__serviceEve.loadEve()
            self.__serviceEnr.loadEnr()
            if cmd.upper() == 'EXIT':
                exit()
            elif cmd.upper() == 'ADD P':
                self.__addPerson()
            elif cmd.upper() == 'SHOW ALL P':
                self.__printPeople()
            elif cmd.upper() == 'MOD P':
                self.__modifyPerson()
            elif cmd.upper() == 'DEL P':
                self.__delPerson()
            elif cmd.upper() == 'SHOW P':
                self.__printPerson()
            elif cmd.upper() == 'MOST PARTICIPANTS':
                self.__mostParticipants()

            elif cmd.upper() == 'ADD E':
                self.__addEvent()
            elif cmd.upper() == 'SHOW ALL E':
                self.__printEvents()
            elif cmd.upper() == 'MOD E':
                self.__modifyEvent()
            elif cmd.upper() == 'DEL E':
                self.__delEvent()
            elif cmd.upper() == 'SHOW E':
                self.__printEvent()
            elif cmd.upper() == 'MOST EVENTS':
                self.__mostEvents()

            elif cmd.upper() == 'SEARCH':
                self.__search()
            elif cmd.upper() == 'ENROLL':
                self.__enroll()
            elif cmd.upper() == 'SHOW ENROLLED':
                self.__showEnrolled()
            elif cmd.upper() == "SORT EVENTS":
                self.__sortEvents()
            elif cmd.upper() == 'RAPORT NOU':
                self.__raportNou()
            else:
                print("Invalid command. Please try again!")
            self.__servicePpl.savePpl()
            self.__serviceEve.saveEve()
            self.__serviceEnr.saveEnr()


    def addPeople(self):
        """
        Adds some random ppl in the list at the start of the program
        :return:
        """
        for i in range(5):
            id = i + 1
            id = str(id)
            name = getRandomString(1, 6)
            adress = getRandomString(1, 6)

            try:
                person = self.__servicePpl.createPerson(id, name, adress)
            except ExceptionRepoP:
                print('Person already in the list!')
            except ValidatorError as err:
                print(err)

    def addEvents(self):
        """
        Adds some random events in the list at the end of the program
        :return:
        """
        for i in range(5):
            id = i + 1
            id = str(id)
            date = getRandomDate()
            time = getRandomTime()
            descr = getRandomString(1, 6)

            try:
                event = self.__serviceEve.createEvent(id, date, time, descr)
            except ExceptionRepoE:
                print('Event already in the list!')

def getRandomString(a, b):
    elem = ''
    r = random.randint(a, b)
    for i in range(r):
        elem += chr(random.randint(ord('a'), ord('z')))
    return elem

def getRandomDate():
    day = random.randint(1, 30)
    month = random.randint(1,12)
    year = random.randint(2018, 2040)
    s = '%s/%s/%s'%(day, month, year)
    return s

def getRandomTime():
    hour = random.randint(0, 23)
    minute = random.randint(0, 59)
    if hour < 10:
        hour = '0' + str(hour)
    else:
        hour = str(hour)
    if minute < 10:
        minute = '0' + str(minute)
    else:
        minute = str(minute)
    t = '%s:%s'%(hour, minute)
    return t
