#include <stdio.h>

int grid[100][100];

void update(int row, int column) {
    int power, overload, maintenance;
    printf("Enter Power Status (1: ON, 0: OFF): ");
    scanf("%d", &power);
    printf("Enter Overload Warning (1: Overloaded, 0: Normal): ");
    scanf("%d", &overload);
    printf("Enter Maintenance Required (1: Yes, 0: No): ");
    scanf("%d", &maintenance);
    
    grid[row][column] = power + (2 * overload) + (4 * maintenance);
    printf("SUCCESS: Sector [%d][%d] status updated successfully!\n", row, column);
}

void query(int row, int column) {
    if(row < 0 || row >= 100 || column < 0 || column >= 100) {
        printf("ERROR: Invalid coordinates! Please enter values between 0-99.\n");
        return;
    }
    
    int report = grid[row][column];
    printf("\n===== SECTOR [%d][%d] STATUS REPORT =====\n", row, column);
    
    if(report & 1)
        printf("• Power Status: ON\n");
    else
        printf("• Power Status: OFF\n");
        
    if(report & 2)
        printf("• Overload Warning: OVERLOADED ??\n");
    else
        printf("• Overload Warning: Normal\n");
        
    if(report & 4)
        printf("• Maintenance: REQUIRED ???\n");
    else
        printf("• Maintenance: Not Required\n");
}

void diagnostic() {
    int overload = 0, maintenance = 0, powerOff = 0;
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(grid[i][j] & 2)
                overload++;
            if(grid[i][j] & 4)
                maintenance++;
            if(!(grid[i][j] & 1))
                powerOff++;
        }
    }
    
    printf("\n===== SYSTEM DIAGNOSTIC REPORT =====\n");
    printf("• Sectors requiring maintenance: %d\n", maintenance);
    printf("• Overloaded sectors: %d\n", overload);
    printf("• Sectors with power OFF: %d\n", powerOff);
    printf("• Total sectors operational: %d\n", 10000 - powerOff);
}

int main() {
    char choice;
    
    // Initialize all sectors to default values (Power ON, Normal, No Maintenance)
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            grid[i][j] = 0;
    
    printf("===== WELCOME TO IESCO POWER GRID MONITORING SYSTEM =====\n");
    
    while(1) {
        int row, column;
        printf("\n===== MAIN MENU =====\n");
        printf("U - Update Sector Status\n");
        printf("Q - Query Sector Status\n");
        printf("D - Run System Diagnostic\n");
        printf("E - Exit System\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch(choice) {
            case 'U':
            case 'u':
                printf("Enter Row and Column (0-99): ");
                scanf("%d %d", &row, &column);
                if(row >= 0 && row < 100 && column >= 0 && column < 100)
                    update(row, column);
                else
                    printf("ERROR: Invalid coordinates! Please enter values between 0-99.\n");
                break;
                
            case 'Q':
            case 'q':
                printf("Enter Row and Column to query (0-99): ");
                scanf("%d %d", &row, &column);
                query(row, column);
                break;
                
            case 'D':
            case 'd':
                diagnostic();
                break;
                
            case 'E':
            case 'e':
                printf("Exiting IESCO Power Grid Monitoring System. Goodbye!\n");
                return 0;
                
            default:
                printf("ERROR: Invalid choice! Please enter U, Q, D, or E.\n");
                break;
        }
    }
    return 0;
}
