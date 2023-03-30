#pragma once

#include <cstdint>
#include <stdexcept>

namespace circular_buffer 
{
    template <class T>
    class circular_buffer{
        private: 
            std::size_t buf_size;
            T* buffer;
            std::size_t tail;
            std::size_t head;
            bool isEmpty;
            bool isFull;
            std::size_t total;

            std::size_t inc_index( std::size_t index )
            {
                std::size_t new_index = index + 1;
                if( new_index == buf_size )
                {
                    new_index = 0;        
                }

                return new_index;
            }

        public: 
            circular_buffer(const std::size_t len)
            {
                clear();
                buf_size = len;

                buffer = new T[buf_size];

                return;
            };

            ~circular_buffer()
            {
                if(buffer != nullptr)
                {
                    delete[] buffer;
                    buffer = nullptr;
                }

                clear();
            }

            T read()
            {
                if((isEmpty == true) && (total == 0))
                {
                    throw std::domain_error( "" );
                }

                T ret = buffer[tail];

                tail = inc_index(tail);

                if(total)
                {
                    total--;
                }

                isFull = false;
                isEmpty = (total == 0) ? true : false;

                return ret;
            };

            void write(const T val)
            {
                if(isFull)
                {
                    throw std::domain_error( "" );
                }

                buffer[head] = val;

                head = inc_index(head);

                total++;

                isEmpty = false;
                isFull = (total == buf_size) ? true : false;
            }

            void overwrite(const T val)
            {
                if(isFull == false)
                {
                    write(val);
                }
                else
                {
                    buffer[tail] = val; 
                    tail = inc_index(tail);
                }
            }

            void clear()
            {
                total = 0;
                tail = 0;
                head = 0;
                isEmpty = true;
                isFull = false;
            }
    };

}  // namespace circular_buffer
