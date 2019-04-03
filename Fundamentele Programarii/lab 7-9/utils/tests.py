"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/20/2018 00:38
"""
from unittest import TestCase

from domain.entities import *
from domain.validators import *
from repository.FileRepositoryPerson import FileRepositoryPerson
from repository.FileRepositoryEvent import FileRepositoryEvent
from repository.FileRepositoryEnroll import FileRepositoryEnroll
from service.servicePerson import ServicePerson
from service.serviceEvent import ServiceEvent
from service.serviceEnroll import ServiceEnroll





def test():
    test_Person()
    test_Event()
    test_Pairs()
    test_storePerson()
    test_storeEvent()
    test_enroll()
    test_createPerson()
    test_deletePerson()
    test_searchInPerson()
    test_modPerson()

def test_Person():
    p = Person(1, 'Cristian', 'Valcea')
    assert p.get_id() == 1
    assert p.get_name() == 'Cristian'
    assert p.get_adress() == 'Valcea'

def test_Event():
    e = Event(10, '11/10/2018', '23:59', 'Balul Bobocilor')
    assert e.get_id() == 10
    assert e.get_date() == '11/10/2018'
    assert e.get_time() == '23:59'
    assert e.get_descr() == 'Balul Bobocilor'

def test_Pairs():
    pair = PairID(1, 2)
    assert pair.get_p() == 1
    assert pair.get_e() == 2

def test_storePerson():
    repo = FileRepositoryPerson()
    repo.clear_file()
    assert len(repo.getAllPeople()) == 0

    person = Person(1, "Johnny", "Strada A")
    repo.storeElem(person)
    assert len(repo.getAllPeople()) == 1
    repo.clear_file()

def test_storeEvent():
    repo = FileRepositoryEvent()
    repo.clear_file()
    assert len(repo.getAllEvents()) == 0

    event = Event(2, "11/10/2014", "23:59", "Vanzare de carte")
    repo.storeElem(event)
    assert len(repo.getAllEvents()) == 1
    repo.clear_file()

def test_enroll():
    repo = FileRepositoryEnroll()
    repo.clear_file()
    assert len(repo.getAllPairs()) == 0

    pair = PairID(1, 2)
    repo.addPair(pair)
    assert len(repo.getAllPairs()) == 1
    repo.clear_file()

def test_createPerson():
    repo = FileRepositoryPerson()
    repo.clear_file()
    val = PersonValidator()
    srv = ServicePerson(repo, val)
    p = Person(1, "Dragos", "Constanta")
    srv.createPerson(p.get_id(), p.get_name(), p.get_adress())
    assert len(repo.getAllPeople()) == 1
    repo.clear_file()

def test_deletePerson():
    repo = FileRepositoryPerson()
    repo.clear_file()
    val = PersonValidator()
    srv = ServicePerson(repo, val)
    p = Person(1 , "Dragos", "Constanta")
    srv.createPerson(p.get_id(), p.get_name(), p.get_adress())
    assert len(repo.getAllPeople()) == 1
    srv.deletePerson(1)
    assert len(repo.getAllPeople()) == 0

def test_searchInPerson():
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

def test_modPerson():
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