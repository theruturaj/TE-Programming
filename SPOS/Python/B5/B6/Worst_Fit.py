def worst_fit(block_size, process_size):
    memory_required = 0
    blocks_needed = []
    if process_size <= block_size[-1]:
        for i in block_size:
            if i>process_size:
                temp_mem = i - process_size
                if memory_required < temp_mem:
                    memory_required = temp_mem
                    blocks_needed.append(i)
                
        return print("Worst fit at block {}.".format(blocks_needed[-1]))
    
    else:
        return print("Process size exceeds available block size!")
      
worst_fit(block_size, process_size)
