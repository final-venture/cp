import subprocess
import os

def track_milestones():
    milestones = {1, 10, 50, 100, 250, 500, 750, 1000}
    
    valid_extensions = ('.cpp', '.py', '.java', '.c', '.js', '.go', '.rs', '.cs')
    
    solved_count = 0
    seen_files = set()
    milestone_records = []

    # Git command: Oldest to newest, showing added/modified files
    cmd = ['git', 'log', '--reverse', '--name-status', '--format=COMMIT|%h|%cs|%s']
    
    try:
        output = subprocess.check_output(cmd, text=True, encoding='utf-8')
    except subprocess.CalledProcessError:
        print("Error: Ensure you are running this inside a Git repository.")
        return

    current_date = ""
    current_msg = ""
    current_hash = ""

    for line in output.splitlines():
        line = line.strip()
        if not line:
            continue
            
        if line.startswith('COMMIT|'):
            # Parse the commit header
            parts = line.split('|', 3)
            if len(parts) == 4:
                _, current_hash, current_date, current_msg = parts
                
        elif line.startswith('A\t'): 
            # 'A' means a file was Added in this commit
            file_path = line.split('\t')[1]
            
            # Check if it's a code file and hasn't been counted yet
            if file_path.endswith(valid_extensions) and file_path not in seen_files:
                seen_files.add(file_path)
                solved_count += 1
                
                if solved_count in milestones:
                    # Extract just the filename
                    problem_name = os.path.basename(file_path)
                    
                    milestone_records.append({
                        'milestone': solved_count,
                        'date': current_date,
                        'problem': problem_name,
                        'commit_hash': current_hash,
                        'commit_msg': current_msg
                    })

    # Print the results
    print(f"Total problems solved: {solved_count}\n")
    print("--- Your Milestones ---")
    
    # Sort just in case, though they should be sequential
    milestone_records.sort(key=lambda x: x['milestone'])
    
    for record in milestone_records:
        print(f"Milestone: Problem #{record['milestone']}")
        print(f"Date:      {record['date']}")
        print(f"File:      {record['problem']} (This file triggered the milestone)")
        print(f"Commit:    [{record['commit_hash']}] {record['commit_msg']}")
        print("-" * 50)

if __name__ == "__main__":
    track_milestones()
    