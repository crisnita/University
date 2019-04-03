"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   10/26/2018 20:02
"""


def getApartament(vect,pos):
    """
    :param vect:
    :param pos:
    :return: returns the number of the apartment in the position indicated by pos
    """
    return vect[pos][0]


def getSum(vect,pos):
    """
    :param vect:
    :param pos:
    :return: returns the sum of the position indicated by pos
    """
    return vect[pos][1]


def getType(vect,pos):
    """
    :param vect:
    :param pos:
    :return: returns the type from the position indicated by pos
    """
    return vect[pos][2]


def creeazaApartament(nrApartament,suma,tip):
    """
    :param nrApartament:
    :param suma:
    :param tip:
    :return: creates an apartment (a list) with nrApartament, suma and tip as elements
    """
    return [nrApartament,suma,tip]
