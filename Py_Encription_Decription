# Encryption library; global variable
codes = {'A':'%', 'a':'9', 'B':'@', 'b':'#', 'C':'8','c':'*','D':'7','d':'^','E':'6',
         'e':'$','F':'5','f':'!','G':'4','g':'>','H':'3','h':'<','I':'3','i':':',
         'J':'2','j':';','K':'1','k':'{','L':'0','l':'}','M':'+','m':'_','N':'~',
         'n':'`','O':'/','o':'|','P':'[','p':']','Q':'.','q':',','R':'(','r':')',
         'S':'=','s':'-','T':'00','t':'11','U':'""',  'u':'~!','V':'><','v':'*_',
         'W':'^*','w':'&:','X':'@!','x':'3^','Y':'$"','y':')#','Z':'{)','z':'+|'}

# Decryption library; global variable
codes_d = {'%':'A', '9':'a', '@':'B', '#':'b', '8':'C','*':'c','7':'D','^':'d','6':'E',
         '$':'e','5':'F','!':'f','4':'G','>':'g','3':'H','<':'h','3':'I',':':'i',
         '2':'J',';':'j','1':'K','{':'k','0':'L','}':'l','+':'M','_':'m','~':'N',
         '`':'n','/':'O','|':'o','[':'P',']':'p','.':'Q',',':'q','(':'R',')':'r',
         '=':'S','-':'s','00':'T','11':'t','""':'U','~!':'u','><':'V','*_':'v',
         '^*':'W','&:':'w','@!':'X','3^':'x','$"':'Y',')#':'y','{)':'Z','+|':'z'}

# encryptes a string
def encryption():
    boy_names = open('boy_names.txt','r')
    read_lines = boy_names.read() # Don't forget to read the file
    my_list = read_lines.splitlines() # Now it's a list

    encrypt_file = open('my_encryption.txt','w')
    
    for word in my_list: # Iterates over each word
        for letter in word: # Iterates over each letter in the word
            if letter in codes:
                letter_value = codes.get(letter,'No display.')
                encrypt_file.write(letter_value+'\n')

    # Closing both files
    boy_names.close()
    encrypt_file.close()    

encryption()

# decryptes a string
def decryption():
    encrypted_file = open('my_encryption.txt','r')
    my_read = encrypted_file.read()
    encrypted_list = my_read.splitlines() # it's all in one list rn
    
    read_line_str = '' 
    for char in encrypted_list:
        if char in codes_d:
            char_value = codes_d.get(char,'No display.')
            read_line_str += char_value

    decrypt_str = ''
    decrypt_str += read_line_str[:5]
    for letter in read_line_str[5:]:
        if letter.isupper(): # Has to be a Boolean
            decrypt_str += ' '
        decrypt_str += letter
    print(decrypt_str)

decryption()
