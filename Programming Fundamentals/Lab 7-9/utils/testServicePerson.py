"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/27/2018 09:24
"""

# EXEMPLU TEST CASE DE LA STANKY

from repository.repositoryPerson import RepositoryPerson
from domain.validators import PersonValidator


def testRemoveFromService()
    repo = RepositoryPerson()
    valid = PersonValidator()
    serv = Serv(repo, valid)

    serv.add('a','b','c')

    serv.remove('a')

    assert serv.size() == 0

