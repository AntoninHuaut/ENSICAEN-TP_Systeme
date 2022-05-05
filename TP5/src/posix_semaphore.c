/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Unix System Programming Laboratory Work / TP de programmation système Unix
 * "Interprocess Communication" / "Communication interprocessus"
 *
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	1.0.0
 * @date 2017-12-14
 */

/**
 * @file posix_semaphore.h
 *
 * Unsafe functions to manipulate POSIX semaphores.
 */

#include "posix_semaphore.h"

Semaphore *create_and_open_semaphore(const char *path, int value)
{
    Semaphore *sem;
    sem = sem_open(path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, value);
    return sem;
}

Semaphore *open_semaphore(const char *path, int value)
{
    Semaphore *sem;
    sem = sem_open(path, O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP, value);
    return sem;
}

void destroy_semaphore(Semaphore *sem, const char *path)
{
    sem_close(sem);
    sem_unlink(path);
}

void P(Semaphore *sem)
{
    sem_wait(sem);
}

void V(Semaphore *sem)
{
    sem_post(sem);
}
