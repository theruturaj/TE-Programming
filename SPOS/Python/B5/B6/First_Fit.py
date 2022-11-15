block_size = (100,500,200,300,600)
process_size = int(input("Enter process size: "))

def first_fit(block_size, process_size):
    block_no = 0
    
    if process_size <= block_size[-1]:
        for i in block_size:
            if i>process_size:
                temp_mem = i - process_size
                block_no += i
                break
                
        return print("First fit at block {}.".format(block_no))
    else:
        return print("Process size exceeds available block size!")
      
first_fit(block_size, process_size)
