# System Monitor Utility

Консольная утилита на BASH для мониторинга системы.

## Возможности
- Просмотр пользователей и их домашних директорий
- Просмотр запущенных процессов
- Перенаправление вывода в файлы
- Фильтрация ошибок
- Подробная справка

## Быстрый старт

```bash
# Сделать скрипт исполняемым
chmod +x sysmonitor.sh

# Показать справку
./sysmonitor.sh --help

# Вывести пользователей
./sysmonitor.sh -u

# Вывести процессы
./sysmonitor.sh -p

# Способ 1: Простое использование
cp sysmonitor.sh /usr/local/bin/sysmonitor
chmod +x /usr/local/bin/sysmonitor

# Способ 2: Использование Makefile
make install

# Способ 3: Установка из DEB пакета
make deb
sudo dpkg -i sysmonitor_1.0_all.deb