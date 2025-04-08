#include "os.h" 


uint64_t page_table_query(uint64_t pt, uint64_t vpn){
    int level;
    uint64_t key;
    uint64_t *current_entry;
    uint64_t physical_address = pt << 12;

    for (level = 4; level > 0; level--) {
        key = (vpn >> (9 * level)) & 0b111111111;
        current_entry = phys_to_virt(physical_address);

        if ((current_entry[key] & 1) == 0) {
            return NO_MAPPING;
        }
        physical_address = current_entry[key] - 1;
    }
    current_entry = phys_to_virt(physical_address);
    key = vpn & 0b111111111;
    if ((current_entry[key] & 1) == 0) {
        return NO_MAPPING;
    }
    return current_entry[key] >> 12;
}
void page_table_update(uint64_t pt, uint64_t vpn, uint64_t ppn){
    int level;
    uint64_t key;
    uint64_t *current_entry;
    uint64_t physical_address = pt << 12;

    for (level = 4; level > 0; level--) {
        key = (vpn >> (9 * level)) & 0b111111111;
        current_entry = phys_to_virt(physical_address);
        if ((current_entry[key] & 1) == 0) {
            if (vpn == NO_MAPPING) {
                return;
            }
            current_entry[key] = (alloc_page_frame() << 12) + 1;
        }
        physical_address = current_entry[key] - 1;
    }
    key = vpn & 0b111111111;
    current_entry = phys_to_virt(physical_address);
    if (ppn == NO_MAPPING) {
        current_entry[key] = 0;
        return;
    }

    current_entry[key] = (ppn << 12) + 1;
}