"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/19/2018 20:44
"""

class ValidatorError(Exception):
    pass

class PersonValidator:

    def __init__(self):
        pass

    def validatePerson(self, person):
        errors = ''
        if person.get_id() == '':
            errors = errors + 'You must have an ID!\n'
        if person.get_name() == '':
            errors = errors + 'You must have a name!\n'
        if person.get_adress() == '':
            errors = errors + 'You must have an adress!\n'
        try:
            int(person.get_id())
        except:
            errors += 'ID is not a number!\n'
        if errors != '':
            raise ValidatorError(errors)



class EventValidator:

    def __init__(self):
        pass

    def validateEvent(self, event):
        errors = ''
        if event.get_id() == '':
            errors = errors + 'You must have an ID!\n'
        if event.get_date() == '':
            errors = errors + 'You must have a date!\n'
        if event.get_time() == '':
            errors = errors + 'You must have a time!\n'
        if event.get_descr() == '':
            errors = errors + 'You must have a description!\n'
        try:
            int(event.get_id())
        except:
            errors += 'ID is not a number!'
        if errors != '':
            raise ValidatorError(errors)

