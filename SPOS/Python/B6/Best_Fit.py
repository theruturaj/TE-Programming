block_size = (100,500,200,300,600)
process_size = int(input("Enter process size: "))

def best_fit(block_size, process_size):
    memory_required = 99999999
    blocks_needed = []
    
    if process_size <= block_size[-1]:
        for i in block_size:
            if i>process_size:
                temp_mem = i - process_size
                if memory_required > temp_mem:
                    memory_required = temp_mem
                    blocks_needed.append(i)
                
        return print("Best fit at block {}.".format(blocks_needed[-1]))
    
    else:
        return print("Process size exceeds available block size!")
      
best_fit(block_size, process_size)
