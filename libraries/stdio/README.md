# Streams
C specifies the use of streams to communicate with terminal
	 and files stored on supported, structured storage device.
A stream is a uniform abstraction for communicating with
	files and devices that consume or produce sequential 
	data such as sockets, keyboards, USB ports and printers.

C uses `FILE` data type to represent streams. A `FILE` object
	holds the internal state information for the connection
	to the associated stream, including:
	- file position indicator
	- buffering information
	- error indicator
	- EOF indicator

# Buffers
Buffering is the process of temporarily storing data in main memory that’s
	passing between a process and a device or file. Buffering improves the
	throughput of I/O operations, which often have high latencies.
Similarly, when a program requests to write to block-oriented devices like
	disks, the driver can cache the data in memory until it has accumulated 
	enough data for one or more device blocks, at which point it writes the 
	data all at once to the disk, improving throughput. This strategy is 
	called flushing the output buffer.

A stream can be in one of three states:
 - Unbuffered Characters are intended to appear from the source or at
the destination as soon as possible. Streams used for error reporting or
logging might be unbuffered.

 - Fully buffered Characters are intended to be transmitted to or from
the host environment as a block when a buffer is filled. Streams used
for file I/O are normally fully buffered to optimize throughput.

 - Line buffered Characters are intended to be transmitted to or from
the host environment as a block when a newline character is encoun-
tered. Streams connected to interactive devices such as terminals are
line-buffered when you open them.

# Stream orientation

Each stream has an orientation that indicates whether the stream contains
	narrow or wide characters. After a stream is associated with an external
	file, but before any operations are performed on it, the stream doesn’t
	 have an orientation. 
Once a wide character I/O function has been applied to a stream without 
	orientation, the stream becomes a wide-oriented stream.
Similarly, once a byte I/O function has been applied to a stream without
	orientation, the stream becomes a byte-oriented stream. 

Multibyte character sequences or narrow characters that can be represented
	 as an object of type char (that are required by the C Standard to be 1 byte) 
	can be written to a byte-oriented stream.

You can reset the orientation of a stream by using the fwide function or by
	closing and then reopening the file.

# File descriptor vs File stream pointer

File descriptor is id assigned to the file during opening and realesed during closing.
Because amount of possible file descriptors is limited it is important to close opened files. Also because opening the files means allocating resources to it.

File stream pointer is representation of communication with the file.
File stream pointer is using File descriptor for recognizing open file inside file system.
