"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/20/2018 00:38
"""
from unittest import TestCase

from domain.entities import *
from domain.validators import *
from utils.FileTestPerson import FileRepositoryPerson
from utils.FileTestEvent import FileRepositoryEvent
from utils.FileTestEnroll import FileRepositoryEnroll
from service.servicePerson import ServicePerson
from service.serviceEvent import ServiceEvent
from service.serviceEnroll import ServiceEnroll



class Test_Person(TestCase):

    def test_Person(self):
        p = Person(1, 'Cristian', 'Valcea')
        assert p.get_id() == 1
        assert p.get_name() == 'Cristian'
        assert p.get_adress() == 'Valcea'


class Test_Event(TestCase):

    def test_Event(self):
        e = Event(10, '11/10/2018', '23:59', 'Balul Bobocilor')
        assert e.get_id() == 10
        assert e.get_date() == '11/10/2018'
        assert e.get_time() == '23:59'
        assert e.get_descr() == 'Balul Bobocilor'


class Test_Pairs(TestCase):

    def test_Pairs(self):
        pair = PairID(1, 2)
        self.assertEqual(pair.get_p(), 1)
        assert pair.get_e() == 2


class Test_storePerson(TestCase):

    def test_storePerson(self):
        repo = FileRepositoryPerson()
        repo.clear_file()
        assert len(repo.getAllPeople()) == 0

        person = Person(1, "Johnny", "Strada A")
        repo.storeElem(person)
        assert len(repo.getAllPeople()) == 1
        repo.clear_file()


class Test_storeEvent(TestCase):

    def test_storeEvent(self):
        repo = FileRepositoryEvent()
        repo.clear_file()
        assert len(repo.getAllEvents()) == 0

        event = Event(2, "11/10/2014", "23:59", "Vanzare de carte")
        repo.storeElem(event)
        assert len(repo.getAllEvents()) == 1
        repo.clear_file()


class Test_enroll(TestCase):

    def test_enroll(self):
        repo = FileRepositoryEnroll()
        repo.clear_file()
        assert len(repo.getAllPairs()) == 0

        pair = PairID(1, 2)
        repo.addPair(pair)
        assert len(repo.getAllPairs()) == 1
        repo.clear_file()


class Test_createPerson(TestCase):

    def test_createPerson(self):
        repo = FileRepositoryPerson()
        repo.clear_file()
        val = PersonValidator()
        srv = ServicePerson(repo, val)
        p = Person(1, "Dragos", "Constanta")
        srv.createPerson(p.get_id(), p.get_name(), p.get_adress())
        assert len(repo.getAllPeople()) == 1
        repo.clear_file()


class Test_deletePerson(TestCase):

    def test_deletePerson(self):
        repo = FileRepositoryPerson()
        repo.clear_file()
        val = PersonValidator()
        srv = ServicePerson(repo, val)
        p = Person(1 , "Dragos", "Constanta")
        srv.createPerson(p.get_id(), p.get_name(), p.get_adress())
        assert len(repo.getAllPeople()) == 1


class Test_searchInPerson(TestCase):

    def test_searchInPerson(self):
        repo = FileRepositoryPerson()
        repo.clear_file()
        val = PersonValidator()
        srv = ServicePerson(repo, val)
        srv.createPerson(1, "Dragos", "Constanta")
        srv.createPerson(2, "Vamos", "Azuga")
        assert srv.searchInPerson(repo.findPerson(1), "os") == True
        assert srv.searchInPerson(repo.findPerson(2), "os") == True
        assert srv.searchInPerson(repo.findPerson(1), "w") == False
        repo.clear_file()


class Test_modPerson(TestCase):

    def test_modPerson(self):
        repo = FileRepositoryPerson()
        repo.clear_file()
        val = PersonValidator()
        srv = ServicePerson(repo, val)
        p = Person(1, "Dragos", "Constanta")
        srv.createPerson(p.get_id(), p.get_name(), p.get_adress())
        assert len(repo.getAllPeople()) == 1
        srv.modPerson(1, "Valeria", "In munti")
        assert len(repo.getAllPeople()) == 1
        assert repo.findPerson(1).get_name() == "Valeria"
        repo.clear_file()

class Test_selectionSort(TestCase):

    def test_selectionSort(self):
        lst2 = [ ['2', '11/10/2018', '10:20', 'Random'], ['1', '10/12/2019', '11:00', 'XYZ'] ]
        repo1 = FileRepositoryEnroll()
        repo2 = FileRepositoryPerson()
        repo3 = FileRepositoryEvent()
        srv = ServiceEnroll(repo2, repo3, repo1)
        lst2 = srv.selectionSort(lst2)
        assert lst2 == [ ['2', '11/10/2018', '10:20', 'Random'], ['1', '10/12/2019', '11:00', 'XYZ'] ]

class Test_shakeSort(TestCase):

    def test_shakeSort(self):
        lst2 = [['2', '11/10/2018', '10:20', 'Random'], ['1', '10/12/2019', '11:00', 'XYZ']]
        repo1 = FileRepositoryEnroll()
        repo2 = FileRepositoryPerson()
        repo3 = FileRepositoryEvent()
        srv = ServiceEnroll(repo2, repo3, repo1)
        lst2 = srv.selectionSort(lst2)
        assert lst2 == [['2', '11/10/2018', '10:20', 'Random'], ['1', '10/12/2019', '11:00', 'XYZ']]
        lst2 = srv.selectionSort(lst2, key=lambda x:x[0])
        assert lst2 == [['1', '10/12/2019', '11:00', 'XYZ'], ['2', '11/10/2018', '10:20', 'Random']]