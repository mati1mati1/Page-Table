# Page-Table
Page Table Management
This repository contains functions related to managing page tables in a virtual memory system. The functions provided include querying and updating page table entries.

Overview
The page table is responsible for mapping virtual page numbers (VPN) to physical page numbers (PPN). The system supports a 4-level page table structure. The provided functions allow querying for a mapping and updating the mappings.

Functions
page_table_query(uint64_t pt, uint64_t vpn)
This function performs a query on the page table to check if there is a valid mapping for the given virtual page number (VPN).

Parameters:

pt: The physical address of the page table.

vpn: The virtual page number to be queried.

Returns:

The physical address corresponding to the VPN if it exists.

NO_MAPPING if there is no valid mapping.

page_table_update(uint64_t pt, uint64_t vpn, uint64_t ppn)
This function updates the page table with a new mapping for a given virtual page number (VPN) to a physical page number (PPN).

Parameters:

pt: The physical address of the page table.

vpn: The virtual page number to be updated.

ppn: The physical page number to which the VPN should be mapped. Use NO_MAPPING to remove the mapping.

Returns:

None. The page table is modified in place.

Requirements
os.h header file must define necessary functions and constants, such as phys_to_virt, alloc_page_frame, and NO_MAPPING.

The system should support 64-bit addresses (for uint64_t types).

Dependencies
Operating System-level functionality (e.g., page frame allocation, physical to virtual address translation).

License
This code is distributed under the MIT License.

