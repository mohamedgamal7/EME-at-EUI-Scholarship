import os

def create_driver_files(driver_name, author, version, date, layer):
    driver_name_caps = driver_name.upper()
    dir_name = driver_name_caps
    
    if not os.path.exists(dir_name):
        os.makedirs(dir_name)
    
    header_content = f"""\

/*Author:      {author}                                                                      
  Version:     {version}                                                                       
  Date:        {date}                                                                             
  Description: {driver_name_caps} driver configuration file                                 
*/

#ifndef _{driver_name_caps}_CONFIG_H
#define _{driver_name_caps}_CONFIG_H

#endif

"""

    private_header_content = f"""\

/*Author:      {author}                                                                      
  Version:     {version}                                                                       
  Date:        {date}                                                                             
  Description: {driver_name_caps} driver private file                                       
*/
#ifndef _{driver_name_caps}_PRIVATE_H
#define _{driver_name_caps}_PRIVATE_H

#endif

"""

    interface_header_content = f"""\
/*Author:      {author}                                                                      
  Version:     {version}                                                                       
  Date:        {date}                                                                             
  Description: {driver_name_caps} driver interface file      
*/
#ifndef _{driver_name_caps}_INTERFACE_H
#define _{driver_name_caps}_INTERFACE_H

#endif
"""

    program_source_content = f"""\
/*Author:      {author}                                                                      
  Version:     {version}                                                                       
  Date:        {date}                                                                             
  Description: {driver_name_caps} driver program file    
*/
#include "./{layer}/{driver_name_caps}_interface.h"
#include "./{layer}/{driver_name_caps}_private.h"
#include "./{layer}/{driver_name_caps}_config.h"

"""

    with open(os.path.join(dir_name, f"{driver_name_caps}_config.h"), "w") as config_file:
        config_file.write(header_content)
    
    with open(os.path.join(dir_name, f"{driver_name_caps}_private.h"), "w") as private_file:
        private_file.write(private_header_content)
    
    with open(os.path.join(dir_name, f"{driver_name_caps}_interface.h"), "w") as interface_file:
        interface_file.write(interface_header_content)
    
    with open(os.path.join(dir_name, f"{driver_name_caps}_program.c"), "w") as program_file:
        program_file.write(program_source_content)

def main():
    driver_name = input("Enter the driver name: ")
    author = input("Enter the author: ")
    version = input("Enter the version: ")
    date = input("Enter the date (dd/mm/yyyy): ")
    layer = input("Enter layer ")
    
    create_driver_files(driver_name, author, version, date, layer)
    print("Driver files created successfully!")

if __name__ == "__main__":
    main()
