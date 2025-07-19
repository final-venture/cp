class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        main_folders = set()
        folder.sort()

        for f in folder:
            unique = True
            ptr = 0
            while ptr < len(f):
                if f[ptr] == '/' and f[:ptr] in main_folders:
                    unique = False
                    break
                ptr += 1
            if f in main_folders:
                unique = False
                    
            if unique:
                main_folders.add(f)
                
        return list(main_folders)
