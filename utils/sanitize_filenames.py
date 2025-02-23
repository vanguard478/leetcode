from pathlib import Path
import re
root = Path('/workspaces/leetcode')

for folder in root.iterdir():
    if folder.is_dir() and folder.name and folder.name[0].isdigit():
        # Use regex to extract the numeric prefix and the remaining part
        match = re.match(r'(\d+)(.*)', folder.name)
        if match:
            num_str, rest = match.groups()
            # Convert the numeric part to an integer and then format it as a 4-digit string
            new_prefix = f"{int(num_str):04d}"
            new_name = new_prefix + rest
            if folder.name != new_name:
                original_name = folder.name
                new_path = folder.with_name(new_name)
                folder.rename(new_path)
                print(f"Renamed '{original_name}' to '{new_name}'")