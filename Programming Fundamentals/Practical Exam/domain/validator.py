"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 11:17
"""
class ValidatorException(Exception):
    pass


class ValidatorMelodie:

    def validate(self, melodie):
        err = ""
        try:
            d = melodie.get_durata()
            d = int(d)
            if d < 0:
                err += "Durata nu este un intreg pozitiv! \n"
        except:
            err += "Durata nu este un intreg pozitiv! \n"
        g = melodie.get_gen()
        if not (g == "Rock" or g == "Pop" or g == "Jazz" or g == "Altele"):
            err += "Gen muzical necorespunzator! \n"

        if err != "":
            raise ValidatorException(err)