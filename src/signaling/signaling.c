#include "signaling.h"
#include <message_buffer.h>

MessageBufferHandle_t msg_handle = NULL;

//Stephen
void signal_handle_calculation(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    return;
}


//Nick
BaseType_t signal_request_calculate(SemaphoreHandle_t request, SemaphoreHandle_t response, struct signal_data *data){
    if (!msg_handle){
        msg_handle = xMessageBufferCreate(1);
    }

    xMessageBufferSend(msg_handle, &data->input, sizeof(data->input), portMAX_DELAY);
    xSemaphoreGive(request);

    // Wait for calculation to finish
    xSemaphoreTake(response, portMAX_DELAY);
    return xMessageBufferReceive(msg_handle, &data->output, 1, portMAX_DELAY) == 1;
}
