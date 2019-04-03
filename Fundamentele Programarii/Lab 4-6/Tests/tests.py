"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   10/28/2018 13:15
"""


from utils.solve import *


def test():
    test_interschimba()
    test_1a()
    test_1b()
    test_2a()
    test_2b()
    test_2c()
    test_5a()
    test_5b()
    test_undo()


def test_interschimba():
    assert interschimba(1,2) == (1,2)
    assert interschimba(2,2) == (2,2)
    assert interschimba(2,1) == (1,2)


def test_1a():
    assert solve_1a([],1,10,'mancare') == [[1,10,'mancare']]
    assert solve_1a([[1,2,'a']],4,3,'apa') == [[1,2,'a'],[4,3,'apa']]
    assert solve_1a([[20,150,'curent'],[15,200,'curent']],16,156,'curent') == [[20,150,'curent'],[15,200,'curent'],[16,156,'curent']]


def test_1b():
    assert solve_1b([[20,150,'curent'], [15,200,'curent']],1 , 100, 'jucarii') == [[20,150,'curent'], [15,100,'jucarii']]
    assert solve_1b([[1,1,'apa'], [2,2,'gaz'], [5,1,'mancare']], 2, 50, 'copii') == [[1,1,'apa'], [2,2,'gaz'], [5,50,'copii']]


def test_2a():
    assert solve_2a([[1,1,'apa'], [2,2,'gaz'], [1,1,'mancare']], 1) == [[2,2,'gaz']]
    assert solve_2a([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare']], 2) == [[1, 1,'apa'], [1,1,'mancare']]


def test_2b():
    assert solve_2b([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'],[5,3,'apa']], 1, 4) == [[5,3,'apa']]
    assert solve_2b([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'],[5,3,'apa']], 6,7 ) == [[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'],[5,3,'apa']]


def test_2c():
    assert solve_2c([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'],[5,3,'apa']],'apa') == [[2, 2, 'gaz'], [1, 1, 'mancare']]
    assert solve_2c([[20,150,'curent'], [15,200,'curent']],'curent') == []


def test_5a():
    assert solve_5a([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'], [5, 3, 'apa']], 'apa') == [[2, 2, 'gaz'],[1, 1, 'mancare']]
    assert solve_5a([[20, 150, 'curent'], [15, 200, 'curent']], 'curent') == []


def test_5b():
    assert solve_5b([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'], [5, 3, 'apa']],3) == [[5,3,'apa']]
    assert solve_5b([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'], [5, 3, 'apa']],4) == []
    assert solve_5b([[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'], [5, 3, 'apa']],1) == [[1, 1, 'apa'], [2, 2, 'gaz'], [1, 1, 'mancare'], [5, 3, 'apa']]


def test_undo():
    assert undo([[1, 2, 'apa'], [2, 3, 'bere']], [[[1, 2, 'apa']], [[1, 2, 'apa'], [2, 3, 'bere']]]) == ([[1, 2, 'apa']], [[[1, 2, 'apa']]])
    assert undo([], []) == ([], [])
    assert undo([[1, 2, 'apa']], [[[1, 2, 'apa']]]) == ([], [])

