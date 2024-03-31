        total = 0        
        mix_count = 1 
        length = len(numbers)
        for i in range(1, length):            
            if numbers[i] != numbers[i - 1]:
                mix_count += 1            
            else:
                total += (mix_count * (mix_count + 1)) // 2                
                mix_count = 1
        total += (mix_count * (mix_count + 1)) // 2
        return total