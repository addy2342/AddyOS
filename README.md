#AddyOS
(https://github.com/addy2342/AddyOS)

Using Altera DE-2 board with Nios II

For the class OS2

#HowTo:
- Flash the Nios II cpu onto the board
- Create a project withthe Altera Monitor Program
- Add *.c files to the project
- Dowanload to the board, run and profit

#Todo List / Status:

###Deliverables
- [ ] Process with Management and Semaphores
- [ ] Memory Management
- [ ] Application
- [ ] Everything
###Communication
- [ ] Send / Receive
 - [ ] FIFO:
  - [x] Structure
  - [x] Init
  - [x] Create
  - [x] Write
  - [ ] Reading
   - [ ] Testing/Fixing
 - [ ] Semaphores
  - [x] Structure
  - [x] Init
  - [ ] Signal
  - [ ] Wait
- [ ] Shared Mem
###Process
- [x] Structure
- [x] Create
  - [ ] Testing/Fixing
- [x] Run
  - [ ] Testing/Fixing
- [ ] Suspend
- [ ] Terminate
###Threads
 - [ ] Synchronization
   - [ ] Signal
   - [ ] Wait
   - [ ] Suspend
###Scheduler (Preemptive)
 - [x] Structure
 - [ ] Context Switching
 - [ ] Types
   - [ ] FCFS
   - [ ] random
   - [ ] RoundRobin
###Memory Management
 - [ ] malloc
 - [ ] free
 - [ ] fragmentation (first, best, or worst fit)
 - [ ] Virtual Addressing 
   - [ ] paging
###I/O Devises
 - [ ] Interrupts
###Application on the OS
 - [ ] self-test (run_self_test)(LOG, FIFO, SEM)(work in progress)
 - [ ] blinkenlights
###Other
- [x] Booting
- [ ] Testing by other Applications from Course Members (Mix and Match)
- [x] LOG write to LCD, LED, 7Seg (todo: VGA)
- [x] avoid librarys
 - [x] Random: LFSR to get rid of the use of math.h
  - from: http://en.wikipedia.org/wiki/Linear_feedback_shift_register
