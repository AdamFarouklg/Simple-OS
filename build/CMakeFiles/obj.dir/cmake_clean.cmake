file(REMOVE_RECURSE
  "CMakeFiles/obj"
  "obj/cpu-tlb.o"
  "obj/cpu-tlbcache.o"
  "obj/cpu.o"
  "obj/loader.o"
  "obj/mem.o"
  "obj/mm-memphy.o"
  "obj/mm-vm.o"
  "obj/mm.o"
  "obj/os.o"
  "obj/paging.o"
  "obj/queue.o"
  "obj/sched.o"
  "obj/timer.o"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/obj.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
