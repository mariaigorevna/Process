import os 
from multiprocessing import Process
from FirstPart import hash_file_print

if __name__ == "__main__":
    dir_path = input("Type directory path: ")
    files_arr = os.listdir(dir_path)
    processes = []
    j = 0

    for file_name in files_arr:
        processes.insert(j, Process(target=hash_file_print, args=(dir_path+'/'+file_name,)))
        processes[j].start()
        j += 1

    for i in range(j):
        processes[i].join()
