"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 12:29
"""


try:
    f = open("repository/alabala.csv", "x")
except:
    f = open("repository/alabala.csv", "w")
f.close()
n = input('dati')