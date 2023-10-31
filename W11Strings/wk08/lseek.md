`lseek` call                    | location in file   
--------------------------------|----------------------
`lseek(fd, 0, SEEK_END)`        | 10000            
`lseek(fd, -1000, SEEK_CUR)`    |  9000         
`lseek(fd, 0, SEEK_SET)`        |     0         
`lseek(fd, -100, SEEK_SET)`     |     0 (EINVAL error)
`lseek(fd, 1000, SEEK_SET)`     |  1000
`lseek(fd, 1000, SEEK_CUR)`     |  2000  

10000 byte long file
    