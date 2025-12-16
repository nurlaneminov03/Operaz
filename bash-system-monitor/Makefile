# System Monitor Utility Makefile

# Переменные
VERSION = 1.0
PACKAGE = sysmonitor
INSTALL_DIR = /usr/local/bin
MAN_DIR = /usr/local/share/man/man1
DOC_DIR = /usr/local/share/doc/$(PACKAGE)

# Цвета для вывода
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m # No Color

# Основная цель
.PHONY: all install uninstall clean test check deb help

all: check

# Проверка синтаксиса
check:
	@echo -e "$(GREEN)Проверка синтаксиса BASH скрипта...$(NC)"
	@bash -n sysmonitor.sh || (echo -e "$(RED)Ошибка в синтаксисе!$(NC)" && exit 1)
	@echo -e "$(GREEN)Синтаксис корректен$(NC)"

# Установка
install:
	@echo -e "$(GREEN)Установка $(PACKAGE)...$(NC)"
	@mkdir -p $(INSTALL_DIR)
	@mkdir -p $(MAN_DIR)
	@mkdir -p $(DOC_DIR)
	@cp sysmonitor.sh $(INSTALL_DIR)/$(PACKAGE)
	@chmod 755 $(INSTALL_DIR)/$(PACKAGE)
	@cp docs/sysmonitor.1 $(MAN_DIR)/
	@cp README.md docs/example-usage.md $(DOC_DIR)/
	@echo -e "$(GREEN)Установка завершена$(NC)"
	@echo "Используйте: $(PACKAGE) --help"

# Удаление
uninstall:
	@echo -e "$(YELLOW)Удаление $(PACKAGE)...$(NC)"
	@rm -f $(INSTALL_DIR)/$(PACKAGE)
	@rm -f $(MAN_DIR)/sysmonitor.1
	@rm -rf $(DOC_DIR)
	@echo -e "$(GREEN)Удаление завершено$(NC)"

# Тестирование
test:
	@echo -e "$(GREEN)Запуск тестов...$(NC)"
	@chmod +x tests/test_basic.sh
	@chmod +x tests/test_files.sh
	@./tests/test_basic.sh
	@./tests/test_files.sh
	@echo -e "$(GREEN)Все тесты пройдены успешно$(NC)"

# Создание DEB пакета
deb:
	@echo -e "$(GREEN)Создание DEB пакета...$(NC)"
	@mkdir -p deb-build/DEBIAN
	@mkdir -p deb-build$(INSTALL_DIR)
	@mkdir -p deb-build$(MAN_DIR)
	@mkdir -p deb-build$(DOC_DIR)
	
	# Копирование файлов
	@cp sysmonitor.sh deb-build$(INSTALL_DIR)/$(PACKAGE)
	@chmod 755 deb-build$(INSTALL_DIR)/$(PACKAGE)
	@cp docs/sysmonitor.1 deb-build$(MAN_DIR)/
	@cp README.md docs/example-usage.md deb-build$(DOC_DIR)/
	
	# Создание control файла
	@echo "Package: $(PACKAGE)" > deb-build/DEBIAN/control
	@echo "Version: $(VERSION)" >> deb-build/DEBIAN/control
	@echo "Section: utils" >> deb-build/DEBIAN/control
	@echo "Priority: optional" >> deb-build/DEBIAN/control
	@echo "Architecture: all" >> deb-build/DEBIAN/control
	@echo "Essential: no" >> deb-build/DEBIAN/control
	@echo "Maintainer: Ваше Имя <ваш.email@example.com>" >> deb-build/DEBIAN/control
	@echo "Description: System monitoring utility" >> deb-build/DEBIAN/control
	@echo " BASH utility for monitoring users and processes with various output options." >> deb-build/DEBIAN/control
	
	# Сборка пакета
	@dpkg-deb --build deb-build $(PACKAGE)_$(VERSION)_all.deb
	@rm -rf deb-build
	@echo -e "$(GREEN)Пакет создан: $(PACKAGE)_$(VERSION)_all.deb$(NC)"

# Очистка
clean:
	@echo -e "$(YELLOW)Очистка временных файлов...$(NC)"
	@rm -f *.deb
	@rm -rf deb-build
	@find . -name "*.txt" -type f -not -path "./tests/expected_output/*" -delete
	@find . -name "*.log" -type f -delete
	@find . -name "test_output*" -type f -delete
	@find . -name "errors*" -type f -delete
	@echo -e "$(GREEN)Очистка завершена$(NC)"

# Справка
help:
	@echo "Доступные команды:"
	@echo "  make all      - Проверка синтаксиса (по умолчанию)"
	@echo "  make check    - Проверка синтаксиса скрипта"
	@echo "  make install  - Установка утилиты"
	@echo "  make uninstall- Удаление утилиты"
	@echo "  make test     - Запуск тестов"
	@echo "  make deb      - Создание DEB пакета"
	@echo "  make clean    - Очистка временных файлов"
	@echo "  make help     - Показать эту справку"