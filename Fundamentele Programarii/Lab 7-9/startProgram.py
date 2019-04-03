"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   11/18/2018 14:48
"""
from repository.FileRepositoryPerson import *
from repository.FileRepositoryEvent import *
from repository.FileRepositoryEnroll import *
from repository.repositoryEvent import *
from repository.repositoryEnroll import *
from repository.repositoryPerson import *
from repository.repositoryEvent import *
from repository.repositoryEnroll import *
from service.servicePerson import *
from service.serviceEvent import *
from service.serviceEnroll import *
from ui.uiConsole import *
from utils.tests import *
from domain.validators import *

valPers = PersonValidator()
valEvent = EventValidator()

# repPers = RepositoryPerson()
# repEvent = RepositoryEvent()
# repEnroll = RepositoryEnroll()


repPers = FileRepositoryPerson()
repEvent = FileRepositoryEvent()
repEnroll = FileRepositoryEnroll()
srvPers = ServicePerson(repPers, valPers)
srvEvent = ServiceEvent(repEvent, valEvent)
srvEnroll = ServiceEnroll(repPers, repEvent, repEnroll)

repPers.clear_file()
repEvent.clear_file()
repEnroll.clear_file()

# test()

start = ui(srvPers, srvEvent, srvEnroll)


start.show_ui()


