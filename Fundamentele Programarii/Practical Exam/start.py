"""
    @author: Nita Andrei-Cristian
    @email:  cristiannita99@yahoo.com
    @date:   2/1/2019 11:03
"""
from service.service import ServiceMuzica
from domain.validator import ValidatorMelodie
from repository.repository import RepositoryMuzica
from ui.ui import ui

repoMuz = RepositoryMuzica()

valMuz = ValidatorMelodie()

servMuz = ServiceMuzica(valMuz, repoMuz)

start = ui(servMuz)

start.show_ui()