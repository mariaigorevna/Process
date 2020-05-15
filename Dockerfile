FROM debian
RUN apt update
RUN apt install g++ python3 python -y
COPY ./FirstPart.py /home/masha/FirstPart.py
COPY ./SecondPart.cpp /home/masha/SecondPart.cpp
COPY ./FirstPart /home/masha/FirstPart
COPY ./SecondPart.py /home/masha/SecondPart.py
COPY ./lab4 /home/masha/lab4
ENTRYPOINT /bin/bash
